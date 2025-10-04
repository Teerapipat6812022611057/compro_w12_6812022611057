#include <stdio.h>

// TODO: เขียนฟังก์ชัน void doubleArray(int *arr, int size)
// ฟังก์ชัน doubleArray รับ pointer ของ array และขนาดของ array
// แล้วทำการคูณค่าทุกตัวใน array ด้วย 2
void doubleArray(int *arr, int size) {
    // วนลูปเพื่อเข้าถึงทุกองค์ประกอบของ array
    for (int i = 0; i < size; i++) {
        // ใช้ pointer arithmetic หรือ array indexing (ซึ่ง C จะแปลงเป็น pointer arithmetic) 
        // เพื่อเข้าถึงและเปลี่ยนค่าของแต่ละองค์ประกอบ
        // *(arr + i) คือการ dereference pointer ที่ชี้ไปยังตำแหน่ง arr + i
        // arr[i] คือรูปแบบที่สั้นกว่าและอ่านง่ายกว่า
        arr[i] = arr[i] * 2; // คูณค่าปัจจุบันด้วย 2
    }
    // ไม่ต้อง return ค่าใดๆ เนื่องจากฟังก์ชันเป็น void และแก้ไขค่าใน array โดยตรง (call by reference)
}

// ฟังก์ชันสำหรับแสดงค่าใน array เพื่อความสะดวกในการแสดงผล
void printArray(const char *label, int *arr, int size) {
    printf("%s: ", label);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // 1. สร้าง array ชื่อ 'a' พร้อมกำหนดค่าเริ่มต้น
    int a[] = {1, 2, 3, 4, 5};
    // 2. คำนวณขนาดของ array โดยใช้ sizeof()
    // size_t total_size = sizeof(a);
    // size_t element_size = sizeof(a[0]);
    // int size = total_size / element_size;
    // หรือกำหนดขนาดโดยตรงตามโจทย์
    int size = 5; 

    // แสดงค่าก่อนคุณ
    // แสดงค่า array ก่อนเรียกฟังก์ชัน
    printArray("Before", a, size); 
    //printf("Before: 1 2 3 4 5 \n"); // แสดงผลลัพธ์ตามตัวอย่าง OUTPUT หากไม่ใช้ฟังก์ชัน printArray
    
    // เรียกใช้ฟังก์ชัน doubleArray
    // ส่งชื่อ array 'a' ซึ่งจะทำหน้าที่เป็น pointer ชี้ไปยังองค์ประกอบแรกของ array
    // และส่งขนาดของ array
    doubleArray(a, size);

    // แสดงค่าหลังคุณ
    // แสดงค่า array หลังเรียกฟังก์ชัน
    printArray("After", a, size);
    //printf("After : 2 4 6 8 10 \n"); // แสดงผลลัพธ์ตามตัวอย่าง OUTPUT หากไม่ใช้ฟังก์ชัน printArray

    return 0;
}