#include <stdio.h>

typedef struct node{
    int performance;
    struct node *next;
}MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {

}

/** 查询第index个学生的成绩 */
int myLinkedListGet(MyLinkedList* obj, int index) {

}

/** 按照降序插入学生的成绩 */
void myLinkedListAdd(MyLinkedList* obj, int performance) {

}

/** 删除第index个学生 */
void myLinkedListDelete(MyLinkedList* obj, int index) {

}

/** 输出该班级的成绩 */
void myLinkedListOutput(MyLinkedList* obj) {

}

/** 将所有班级的成绩合并降序输出 */
void merge(MyLinkedList* obj[]) {

}

int main(){
    MyLinkedList* obj[3];




    while (1){
        printf("1.insert 2.delete 3.search 4.output 5.rank\n");
        int op;
        scanf("%d", &op);
        int class;
        int index;
        int performance;
        switch(op){
            case 1:
                printf("input class\n");
                scanf("%d", &class);
                printf("input performance\n");
                scanf("%d", &performance);
                myLinkedListAdd(obj[class-1], performance);
                break;
            case 2:
                printf("input class\n");
                scanf("%d", &class);
                printf("input index\n");
                scanf("%d", &index);
                myLinkedListDelete(obj[class-1], index);
                break;
            case 3:
                printf("input class\n");
                scanf("%d", &class);
                printf("input index\n");
                scanf("%d", &index);
                printf("%d\n",myLinkedListGet(obj[class-1], index));
                break;
            case 4:
                myLinkedListOutput(obj[0]);
                myLinkedListOutput(obj[1]);
                myLinkedListOutput(obj[2]);
                break;
            case 5:
                merge(obj);
                break;
            default:
                return 0;
        }
        printf("###################################\n");
    }
}
