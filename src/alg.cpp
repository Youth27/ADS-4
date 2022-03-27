// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int schet = 0;
  for (int i = 1; i < len; i++) {
    for (int k = i + 1; k < len; k++) {
      if (arr[i] + arr[k] == value) {
        schet += 1;
      }
    }
  }
  return schet;
}
int countPairs2(int *arr, int len, int value) {
  int schet2 = 0;
  for (int j = 0; j < len - 1; j++) {
    for (int q = len - 1; q > j; q--) {
      if (arr[j] + arr[q] == value) {
        schet2 += 1;
      }
    }
  }
  return schet2;
}
int countPairs3(int *arr, int len, int value) {
  int schet3 = 0;
  for (int l = 0; l < len - 1; l++) {
    int left = l, right = len;
    while (left < right - 1) {
      int sered = (left + right) / 2;
      if (arr[l] + arr[sered] == value) {
        schet3 += 1;
        int s = sered + 1;
        while (arr[l] + arr[s] == value && s < right) {
          schet3 += 1;
          s += 1;
        }
        s = sered - 1;
        while (arr[l] + arr[s] == value && s > left) {
          schet3 += 1;
          s--;
        }
        break;
      }
      if (arr[l] + arr[sered] > value)
        right = sered;
      else
        left = sered;
    }
  }
  return schet3;
}
