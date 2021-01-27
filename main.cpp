#include <iostream>
#include <vector>

using namespace std;

void print_tab(int* tab, int count) {
    for(int i = 0; i<count;cout<<tab[i++]<<'\t');
    cout<<endl;
}

void print_tab(vector <int> tab) {
    for(int i = 0; i<tab.size(); cout<<tab[i++]<<'\t');
    cout<<endl;
}

int* copy_tab(int* tab, int count) {
    int* cop = new int[count];
    for(int i = 0; i<count; i++)
        cop[i] = tab[i];
    return(cop);
}

void bubble_sort_tab(int* tab ,int count) {
    int t;
    bool check = true;
    for(int i = count - 2; i && check; i--) {
        check = false;
        for(int j=0; j <= i; j++) {
            if(tab[j] > tab[j+1]) {
                t = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = t;
                check = true;
            }
        }
    }
}


void heapify(int* tab, int n, int count) { // heapifies subtree with root in n
    int min = n, t;
    if((tab[(n<<1)+1] < tab[min]) && (((n<<1)+1)<count))
        min = (n<<1)+1;
    if((tab[(n+1)<<1] < tab[min]) && (((n+1)<<1)<count))
        min = (n+1)<<1;
    if(min != n) {
        t = tab[n];
        tab[n] = tab[min];
        tab[min] = t;

        heapify(tab, min, count); // subtree
    }
}

void heap_sort_tab(int* tab, int count) {
    if(count) {
        for (int i = (count<<1)-1; i>=0; i--)
            heapify(tab, i, count);

        heap_sort_tab(tab+1, count-1); // quirky recursion
    }
}

int main() {
    vector <int> vec;

    int* tab = new int[9]{3,4,6,2,7,1,24,9,5};
    vec = {1,5,4,6,3,7,2,8};
    print_tab(vec);

    int* copitiy = copy_tab(tab, 9);

    cout << "Heap Section!!!\n\n\n";

    heap_sort_tab(tab, 9);

    cout << "Test readings Section!!!\n\n\n";
    print_tab(tab, 9);
    print_tab(copitiy, 9);

    return 0;
}