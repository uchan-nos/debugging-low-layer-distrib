int FormatInt(char* s, int value) {
  if (value == 0) {
    s[0] = '0';
    s[1] = '\0';
    return 1;
  }

  int minus = 0;
  if (value < 0) {
    s[0] = '-';
    ++s;
    value = -value;
    minus = 1;
  }

  char tmp[11];
  int n = 0;
  while (value) {
    tmp[n] = (value % 10) + '0';
    value /= 10;
    ++n;
  }

  for (int i = 0; i < n; ++i) {
    s[i] = tmp[n - i - 1];
  }
  s[n] = '\0';
  return minus + n;
}
