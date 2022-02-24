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

int first_greater_index(int* tab, int count, int x) {
    for (int i = 0; i < count; i++)
        if (tab[i] > x)
            return i;
    return count;
}

int bin_first_greater_index(int* tab, int count, int x) {
    int m = count / 2;
    if (count == 1) {
        if (tab[0] < x)
            return 1;
        else
            return 0;
    }
    else if (count == 0) {
        return 0;
    }
    if (tab[m] < x)
        return m + 1 + bin_first_greater_index(tab + m + 1, count - m - 1, x);
    else
        return bin_first_greater_index(tab, m, x);
}

void tab_insert(int* tab, int count) {
    int t = tab[count - 1];
    for (int i = count - 2; i >= 0; i--) {
        tab[i + 1] = tab[i];
    }
    tab[0] = t;
}

void tab_swap(int* tab, int count) {
    int t = tab[0];
    tab[0] = tab[count - 1];
    tab[count - 1] = t;
}

void insertion_sort(int* tab, int count) {
    for (int i = 0; i < count - 1; i++) {
        int ts = bin_first_greater_index(tab, i + 1, tab[i + 1]);
        tab_insert(tab + ts, i-ts+2);
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

    cout << first_greater_index(tab, 5, 9) << '\t' << first_greater_index_bin(tab, 5, 9);

    return 0;
}
