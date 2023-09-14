#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void* l, const void* n) 
{
    return (*(int*)l - *(int*)n);
}

void elevator(int arr[], int head, char* dn, int disk_size, int size)
{
    int seek_num = 0;
    int dt, cur_track;
    int leftside[size], rightside[size];
    int seek_seq[size + 3];
    int m_scan = 0, s_scan = 0;
    int go = 2;
    int ind = 0;

    if (strcmp(dn, "leftside") == 0)
        leftside[m_scan++] = 0;
    else if (strcmp(dn, "rightside") == 0)
        rightside[s_scan++] = disk_size - 1;

    for (int p_s = 0; p_s < size; p_s++) 
    {
        if (arr[p_s] < head)
            leftside[m_scan++] = arr[p_s];
        if (arr[p_s] > head)
            rightside[s_scan++] = arr[p_s];
    }
   
    qsort(leftside, m_scan, sizeof(int), comp);
    qsort(rightside, s_scan, sizeof(int), comp);

    while (go--) 
    {
        if (strcmp(dn, "leftside") == 0) 
        {
            for (int p_s = m_scan - 1; p_s >= 0; p_s--) 
            {
                cur_track = leftside[p_s];
                seek_seq[ind++] = cur_track;
                dt = abs(cur_track - head);
                seek_num += dt;
                head = cur_track;
            }
            dn = "rightside";
        }
        else if (strcmp(dn, "rightside") == 0)
        {
            for (int p_s = 0; p_s < s_scan; p_s++) 
            {
                cur_track = rightside[p_s];
                seek_seq[ind++] = cur_track;
                dt = abs(cur_track - head);
                seek_num += dt;
                head = cur_track;
            }
            dn = "leftside";
        }
    }

    printf("Seek sequence: ");
    for (int p_s = 0; p_s < ind; p_s++) 
    {
        printf("%d ", seek_seq[p_s]);
    }
    printf("\n");

    printf("Number of seek process: %d\n", seek_num);
    printf("Seek time: %dms\n", seek_num * 6);
}
int main()
{
    int arr[] = {10, 22, 20, 2, 40, 6, 38};
    int size = sizeof(arr) / sizeof(arr[0]);
    int head = 20;
    int disk_size = 40;
    char dn[] = "rightside";

    printf("Request sequence: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nHead: %d\n\n", head);
    elevator(arr, head, dn, disk_size, size);

    return 0;
}
