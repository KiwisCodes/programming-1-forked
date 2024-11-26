#include <stdio.h>
#include "sort.h"
#include "compare_func.h"


//nếu mà mình chỉ compile cái main thì ko được là tai vì cái hàm bubble_sort_with_type nó nằm trong sort.c
//điều mình cần làm là gom 2 cái main.c và sort .c thành 1 file thoi
//gcc main.c sort.c -o program
//thì program lúc này sẽ có cả 2 file main.c và sort.c
// nma trong main.c đã có sort.h -> sort.h đã có compare_func.h
// trong sort.c lại có sort.h -> sort.h đã có compare_func.h
// cho nên là nó sẽ bị multiple definition
// mình phải xoá bớt hoặc thêm cái j đó vào đúng file để nó ko bị như vậy nữa
// trong main.c hoặc trong sort.c phải bỏ 1 cái sort.h đi
// cách để chương trình này chạy là cần đầu tiên compile cái main.c thành main.o và sort.c thành sort.o và sau đó
// thì mình sẽ link 2 cái file đó vào 1 cái file executable tên là program
// nếu bỏ sort.h của main.c rồi làm theo các bước trên thì lỗi tại vì main.c có gọi 
/*
    bubble_sort(arr, N); // [1, 3, 4, 6, 7]
    bubble_sort_with_type(arr, N, less);
    bubble_sort_with_type(arr, N, greater);
*/

// ta bắt buộc phải để sort.h để main.c compile ko bị lỗi

// nếu ta bỏ sort.h trong sort.c thì ko bị lỗi tại sort.c ko dùng những hàm có trong sort.h mà file sort.c
// chỉ declare các hàm mới là bubble và bubble j đó
// nhưng sau đó nếu ta link 2 cái main.o và sort.o vào program gcc main.o sort.o -o program thì nó lỗi bởi vì 
// khi này cả chương trình nó có dùng cái swap_counter ở trong cái sort.h
// (trong main.ccó print ra swap_counter, còn sort.c thì có initialize nó bằng 0)


// lúc này chỉ còn 1 cách là trong sort.c vẫn có sort.h
// nhưng mà nếu như vậy thì cả main.c và sort.c đề có sort.h và nếu v thì cả 2 đều declare lại các hàm ở trong cái
// compare_func.h

// nên là ta sẽ bỏ cái compare_func.h ở trong cái sort.h và include compare_func.h ở những file .c nào cần (file main.c cần)



/*
đoạn này ta sẽ nói về cái 
#define DEBUG 

#ifdef DEBUG
extern int swap_counter;
#endif 


#define DEBUG có nghĩa là cho chương trình ở trạng thái DEBUG

nếu mình comment dòng này thì nếu vẫn muốn trong trạng thái DEBUG thì mình sẽ ghi như sau khi compile file:
gcc -c main.c -DDEBUG -o main.o

dùng cái này hay, nếu cần debug thì để cái #define DEBUG ko cần xoá tất cả dòng print để DEBUG
*/

/*
còn cái
*/

int main()
{
    int N = 5;
    int arr[] = { 1, 4, 3, 7, 6 };

    bubble_sort(arr, N); // [1, 3, 4, 6, 7]
    bubble_sort_with_type(arr, N, less);
    bubble_sort_with_type(arr, N, greater);

#ifdef DEBUG
    printf("number of swap: %d\n", swap_counter);
#endif 

    return 0; // set break point
}

