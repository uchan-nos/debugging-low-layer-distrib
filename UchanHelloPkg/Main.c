#include  <Uefi.h>
#include  <Library/UefiLib.h>
#include  <Library/UefiBootServicesTableLib.h>
#include  <Library/CpuLib.h>

EFI_STATUS EFIAPI UefiMain(
    EFI_HANDLE image_handle,
    EFI_SYSTEM_TABLE* system_table) {
  EFI_STATUS status;
  EFI_MEMORY_DESCRIPTOR* map = NULL;
  UINTN map_size = 0, map_key, desc_size;
  UINT32 desc_ver;

  status = gBS->GetMemoryMap(&map_size, map, &map_key, &desc_size, &desc_ver);
  if (status != EFI_BUFFER_TOO_SMALL) {
    return status;
  }
  map_size += 1024;
  status = gBS->AllocatePool(EfiLoaderData, map_size, (VOID**)&map);
  if (EFI_ERROR(status)) {
    return status;
  }
  status = gBS->GetMemoryMap(&map_size, map, &map_key, &desc_size, &desc_ver);
  if (EFI_ERROR(status)) {
    return status;
  }

  Print(L"calling ExitBootServices ...\n");
  status = gBS->ExitBootServices(image_handle, map_key);
  if (EFI_ERROR(status)) {
    return status;
  }
  Print(L"ExitBootServices succeeded\n");
  while (1) CpuSleep();

  return EFI_SUCCESS;
}
