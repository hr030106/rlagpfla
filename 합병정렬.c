#include <stdio.h>

void merge(int a[], int low, int mid, int hight)    //�и��� �迭 ���� �� ���� �Լ�
{
  int b[6];
  int i = low;        //���� ����
  int j = mid + 1;    //������ ����
  int k = 0;          //�迭 b�� �ε��� ��

  while(i <= mid && j <= hight)
  {
    if(a[i] <= a[j])        //�и��� ���� �迭�� ������ �迭 ��
      b[k++] = a[i++];
    else
      b[k++] = a[j++];
  }
  while(i <= mid)             //������ ���� ���� �迭�� �ִٸ� �迭 b�� ���� ä���
    b[k++] = a[i++];
  while(j <= hight)           //������ ���� ������ �迭�� �ִٸ� �迭 b�� ���� ä���
    b[k++] = a[j++];
  k--;

  while(k >= 0)               //�迭 b ������ �迭 a ���뿡 �����
  {
    a[low + k] = b[k];
    k--;
  }
}
void mergeSort(int a[], int low, int hight)    //�迭�� ��Ҹ� �����ϴ� �Լ�
{

  int mid;
  if(low < hight)
  {
    mid = (low + hight) / 2;
    mergeSort(a, low, mid);            //���� �迭�� ��� �и�
    mergeSort(a, mid + 1, hight);      //������ �迭�� ��� �и�
    merge(a, low, mid, hight);         //�и��� �迭 ���� �� ���� �Լ�
  }
}
int main(void)
{
  int arr[6] = { 3, 4, 5, 2, 1, 6 };
  int i;

  mergeSort(arr, 0, 6 - 1);    //�迭�� ��Ҹ� �����ϴ� �Լ�

    for(i = 0; i < 6; i++)
    printf("%d ", arr[i]);
}
