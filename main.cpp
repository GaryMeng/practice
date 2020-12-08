#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

Node* CreateLindedList(int* array, int length) {

    Node *head = new Node(array[0]);
    head -> next = NULL;
    Node *last = head;

    for (int i = 1; i < length; i ++) {

        Node *var = new Node(array[i]);
        var -> next = NULL;
        last -> next = var;
        // ��βָ��var
        last = var;
    }
    return head;
}

Node* ReverseLinkedList(Node* node) {

    if (node == NULL || node -> next == NULL)
        return node;

    // ��ת������׶�β
    Node *toDestory = node;
    Node *reversedTail = new Node(node -> val);
    reversedTail -> next = NULL;
    Node *reversedHead = reversedTail;
    Node *prev = reversedTail;

    while (node -> next != NULL) {

        node = node -> next;
        reversedHead = new Node(node -> val);
        reversedHead -> next = prev;
        prev = reversedHead;

        // ����ռ�
        delete toDestory;
        toDestory = node;
    }
    return reversedHead;
}

void DestoryLinkedList(Node* node) {

    // û������ֱ�ӷ���
    if (node == NULL )
        return;

    Node *head = node;
    Node *prev = node;

    while(head != NULL) {

        head = head -> next;
        printf("\n Deleting %d", prev -> val);
        delete prev;
        prev = head;
    }
}

void PrintList(Node* node) {

    Node* head = node;
    while(head != NULL) {

        printf("%d\t", head -> val);
        head = head -> next;
    }
}

int main(int argc, int** argv)
{
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    Node *head = CreateLindedList(arr, sizeof(arr) / sizeof(arr[0]));
    printf("%s\t", "��ӡ����");
    PrintList(head);

    Node *reversed = ReverseLinkedList(head);
    printf("\n%s\t", "��ӡ��ת����");
    PrintList(reversed);

    DestoryLinkedList(reversed);

    return 0;
}
