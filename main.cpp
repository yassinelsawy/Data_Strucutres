#include <bits/stdc++.h>
#define ll long long
using namespace std;

void read() {
#ifndef ONLINE_JUDGE
    freopen("Fazza3IN.txt", "r", stdin);
    freopen("Fazza3OU.txt", "w", stdout);
#endif
}

void insertionSort(int arr[],int n){

    int key , j;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void SelectionSort(int arr[], int n){

    int minIdx;

    for(int i = 0;i < n-1; i++){

        minIdx = i;

        for(int j = i + 1 ; j < n; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

void bubbleSort(int arr[],int n){
    for(int i = 0; i < n; i++){
        for(int j = 1 ; j < n - i; j++){
            if(arr[j-1] > arr[j]) swap(arr[j-1],arr[j]);
        }
    }
}

// MERGE Sort
void merge(int arr[],int l, int m, int r){
    int i = 0,j = 0,
    k = l;
    int n1 = m - l + 1;
    int n2 = r - m;
    int arrL[n1] , arrR[n2];
    for(int f = 0; f < n1;f++){
        arrL[f] = arr[f + l];
    }
    for(int f = 0; f < n2;f++){
        arrR[f] = arr[f + m + 1];
    }
    while(i < n1 && j < n2){
        if(arrL[i]<=arrR[j]){
            arr[k] = arrL[i];
            i++;k++;
        }else{
            arr[k] = arrR[j];
            j++;k++;
        }
    }
    while(i < n1){
        arr[k] = arrL[i];
        i++;k++;
    }
    while(j < n2){
        arr[k] = arrR[j];
        j++;k++;
    }
}
void mergeSortRec(int arr[] , int l , int r){
    if(l >= r) return;
    else{
        //int m = l + (r - l)/2; // adel nesim
        int m = (l+r)/2; // Dr. Beshir
        mergeSortRec(arr, l , m);
        mergeSortRec(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// QUICK Sort
int quick(int arr[],int l,int r){
    int i = l = 0, j = i+1;
    int piv = i;
    while (i < r && j < r){
        if(arr[piv] < arr[j]){
            j++;
        }else{
            i++;
            swap(arr[i],arr[j]);
            j++;
        }
    }
    swap(arr[piv],arr[i]);
    return i;
}
void quickSort(int arr[], int l, int r){

    if(l >= r) return;
    else{
        int piv = quick(arr,l,r);
        quickSort(arr,l,piv - 1);
        quickSort(arr,piv+1,r);
    }
}

const int max_size = 100;
template<class T>
class stck {
    int top;
    T item[max_size];
public:
    stck() {
        top = -1;
    }
    void push(T element) {
        if (top >= max_size - 1) {
            cout << "The stack is full";
        } else {
            top++;
            item[top] = element;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    void pop() {
        if (isEmpty()) {
            cout << "The stack is already empty";
        } else {
            top--;
        }
    }

    void returnTop() {
        if (!isEmpty()) {
            cout << item[top]<< endl;
        }
    }
    
    void print(){
        cout<<"[ ";
        for (int i = top; i >= 0 ; i--) {
            cout<<item  [i]<< (i==0? " ": ", ");
        }
        cout<<"]";
        cout << endl;
    }
};

template <class T>
class linked_stack{
    struct Node{
        T data;
        Node *next;
    };
    Node *top = NULL;
    int length = 0;
public:
    bool isEmpty(){
        return length == 0;
    }
    void push(T element){
        Node *newnode = new Node(element);
        newnode->next = top;
        top = newnode;
        length++;
    }
    void pop(){
        Node *temp;
        temp = top;
        top = top->next;
        delete temp;
        length--;
    }
    void print(){
        Node *trav = top;
        cout<<"[";
        while(trav!=NULL){
            cout<< trav->data<<(trav->next==NULL?" ":", ");
            trav = trav->next;
        }
        cout<<"]";
        cout<<endl;
    }
};

template<class T>
class linked_list{
    struct Node{
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int length = 0;
public:
    bool isEmpty(){
        return length == 0;
    }
    void insertFront(T element){
        Node* newnode = new Node(element);
        if(isEmpty()){
            head = tail = newnode;
            newnode->next = NULL;
        }else{
            newnode->next = head;
            head = newnode;
        }
        length++;
    }
    void insertBack(T element){
        Node* newnode = new Node(element);
        if(length == 0){
            head = tail = newnode;
            newnode->next = NULL;
        }else{
            tail->next = newnode;
            newnode->next = NULL;
            tail = newnode;
        }
        length++;
    }
    void insertAtPos(int pos , T element){
        Node* newnode = new Node(element);
        Node* Cur = head;
        if (pos == 0 ) insertFront(element);
        else if(pos == length) insertBack(element);
        else{
            if(pos < 0 || pos > length){
                cout<<"Out of range" << endl;
                return;
            }
            else{
                for (int i = 1; i < pos; ++i) {
                    Cur = Cur->next;
                }
                newnode->next = Cur->next;
                Cur->next = newnode;
                length++;
            }

        }
    }
    void removeFirst(){
        if(length == 0) return;
        else if(length == 1){
            delete head;
            head = tail = NULL;
            length--;
        }else{
            Node* cur = head;
            head = head->next;
            delete cur;
            length--;
        }
    }
    void removeLast(){
        if (length == 0) return;
        else if(length == 1){
            delete tail;
            head = tail = NULL;
            length--;
        }else{
            Node* cur = head->next;
            Node* prev = head;
            while(cur != tail){
                prev = cur;
                cur = cur->next;
            }
            delete cur;
            prev -> next = NULL;
            tail = prev;
            length--;
        }
    }
    void removeEle(T element){
        Node *cur,*prev;
        if(head->data == element) removeFirst();
        else{
            cur = head-> next , prev = head;
            while(cur != tail){
                if(cur->data == element) break;
                else {
                    prev = cur;
                    cur = cur->next;
                }
            }
        }
        if(cur == NULL) cout<<"Not found \n";
        else{
            prev->next = cur->next;
            if(tail == cur){
                tail = prev;
//                removeLast();
            }
            delete cur;
            length--;
        }
    }
    void reverse(){
        Node *cur, *prev,*nxt;
        prev = NULL , cur = head , nxt = cur->next;
        while(nxt != NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        head = prev; // lma awsl le akher element
    }
    void print(){
        Node* Cur = head;
        while(Cur != NULL){
            cout<<Cur->data<<" ";
            Cur = Cur->next;
        }
    }
};

int operWeight(char op){
    int weight = -1;
    switch(op){
        case'+':
        case '-':
            weight = 1;
        case '*':
        case'/':
            weight = 2;
    }
    return weight;
}

bool is_operand(char c){
    return (isalnum(c));
}
bool is_operator(char c){
    if(c == '+'||c == '-'||c == '*'||c == '/'||c == '$') return true;
    return false;
}

int HasHigherPrecedence(char op1, char op2){
    int op1weight = operWeight(op1);
    int op2weight = operWeight(op2);
    if (op1weight == op2weight)
    {
        return true;
    }
    return op1weight > op2weight;
}

string infixToPostfix(string exp){
    stack<char>s;
    string postfix = "";
    for(unsigned int i = 0; i< exp.length();i++){

        // Checking the character if  there is space
        if(exp[i] == ' '|| exp[i] == ',')
            continue;
        else if(is_operator(exp[i])){
           while(!s.empty() && s.top() != '(' && HasHigherPrecedence(s.top(),exp[i])){
               postfix+=s.top();
               s.pop();
           }
           s.push(exp[i]);
       }
       // If the character is operand (Number)
        else if(is_operand(exp[i])){
           postfix+=exp[i];
        }

        else if(exp[i] == '(') s.push(exp[i]);

        else if (exp[i]==')'){
           // bfdl a3ml pop mn l stack le kol haga me ben l brackets
           while(!s.empty() && s.top()!='('){
               postfix+=s.top();
               s.pop();
           }
           s.pop();
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}

void Print(int arr[],int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    read();
        //      Linked List     //
// --------------------------------------------------- //
    linked_list<int> l;
/*
    l.insertFront(10);
    l.insertBack(20);
    l.insertBack(55);
    l.insertFront(25);
    l.insertAtPos(,4);
    l.removeFirst();
    l.removeLast();
    l.removeEle(10);
    l.reverse();
    l.print();
*/
        //      Stack      //
// --------------------------------------------------- //
    stck<int> s;
/*
    s.push(50);
    s.push(5);
    s.push(70);
    s.push(32);
    s.pop();
    s.pop();
    s.print();
    s.returnTop();
*/
        //      Linked Stack     //
// --------------------------------------------------- //
    linked_stack<int> ls;
//    ls.push(50);
//    ls.push(5);
//    ls.push(70);
//    ls.push(32);
//    ls.pop();
//    ls.print();

    //      InFix to PostFix     //
// --------------------------------------------------- //
    string po = "10 * (2 + 1 + 5)/2-1";
    cout << infixToPostfix(po);


    return 0;
}
