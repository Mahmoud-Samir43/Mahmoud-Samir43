#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
using namespace std;
struct books;
struct users;
struct borrowed;
void borrow_list(borrowed array[], int d);
void wrong_choice();
int menu();
int borrow(books array[], users aray[], borrowed arr[]);
void book_back(borrowed ar[], books arr[], users arra[]);
void search(books array[], int n);
struct users {
  string name;
  string book_borrowed;
};
struct borrowed {
  string user_name;
  string book_borrow;
};
struct books {
public:
  int id;
  string name;
  string prefix;
  int count;
};

void wrong_choice(int z) {

  if (z <= 0 || z >= 11) {
    cout << " choose a viable option" << endl;
  }
}

int add_user(users array[]) {
  static int count = 0;
  cout << "enter user name" << endl;
  cin >> array[count].name;
  count++;
  return count;
}

void print_users(users array[]) {
  for (int i = 0; i < 100; i++) {
    if (array[i].name != "") {
      cout << " " << array[i].name << endl;
    }
  }
}

bool compare(books a, books b) { return a.name < b.name; }

void sort_name(books array[]) {
  sort(array, array + 100, compare);
  for (int i = 0; i < 100; i++) {
    if (array[i].name != "") {
      cout << array[i].name << endl;
    }
  }
}
void sort_id(books array[]) {
  pair<int, string> pairt[100];
  for (int i = 0; i < 100; i++) {
    pairt[i].first = array[i].id;
    pairt[i].second = array[i].name;
  }
  sort(pairt, pairt + 100);
  for (int i = 0; i < 100; i++) {
    if (pairt[i].first != 0 && pairt[i].second != "" && array[i].count != 0) {
      cout << "ID --> " << pairt[i].first << "  name of the book --> "
           << pairt[i].second << "  no.of copies --> " << array[i].count
           << endl;
    }
  }
}
int add_books(books array[]) {
  static int z{0};
  cout << "add id , name , copies" << endl;
  cin >> array[z].id >> array[z].name >> array[z].count;
  z++;
  return z;
}
int main() {
  int n, z, uc, a;
  borrowed array[100];
  users u_array[100];
  books b_array[100];
  while (n != 10) {
    n = menu();
    if (n == 1) {
      z = add_books(b_array);
      continue;
    }

    if (n == 2) {
      search(b_array, z);
      continue;
    }
    if (n == 3) {
      a = borrow(b_array, u_array, array);
      continue;
    }
    if (n == 4) {
      book_back(array, b_array, u_array);
      continue;
    }
    if (n == 5) {
      sort_name(b_array);
      continue;
    }
    if (n == 6) {
      sort_id(b_array);
      continue;
    }
    if (n == 7) {
      borrow_list(array, a);
      continue;
    }
    if (n == 8) {
      print_users(u_array);
      continue;
    }
    if (n == 9) {
      uc = add_user(u_array);
      continue;
    }
  }
}

int menu() {
  int n;

  cout << endl << "pick a choice..." << endl;
  cout << "1) add book." << endl;
  cout << "2) search books by name." << endl;
  cout << "3) user borrow book." << endl;
  cout << "4) user return book." << endl;
  cout << "5) print library by name." << endl;
  cout << "6) print library by ID." << endl;
  cout << "7) print who borrowed a book buy name." << endl;
  cout << "8) print users." << endl;
  cout << "9) add user." << endl;
  cout << "10) exit." << endl;
  cin >> n;
  wrong_choice(n);
  return n;
}

int borrow(books array[], users aray[], borrowed arr[]) {
  int u, b;
  static int d = 0;
  cout << " who is the user " << endl;
  for (int i = 0; i < 100; i++) {
    if (aray[i].name != "") {
      cout << i << " " << aray[i].name << endl;
    }
  }
  cin >> u;
  cout << "choose book" << endl;
  for (int i = 0; i < 100; i++) {
    if (array[i].name != "") {
      cout << i << " " << array[i].name << endl;
    }
  }
  cin >> b;
  if (array[b].count == 0) {
    cout << "sorry there is not enough copies of " << array[b].name << endl;
    return 0;
  } else {
    for (int i = 0; i < 100; i++) {
      if (arr[i].book_borrow == array[b].name &&
          arr[i].user_name == aray[u].name) {
        cout << "sorry you already have a copy of the book";
        return 0;
      }
    }
    arr[d].user_name = aray[u].name;
    arr[d].book_borrow = array[b].name;
    array[b].count--;
    d++;
  }

  return d;
}

void borrow_list(borrowed array[], int d) {
  for (int i = 0; i <= d; i++) {
    if (array[i].book_borrow != "" && array[i].user_name != "") {
      cout << array[i].user_name << " " << array[i].book_borrow << endl;
    }
  }
}

void book_back(borrowed ar[], books arr[], users arra[]) {
  int j;
  for (int i = 0; i < 100; i++) {
    if (ar[i].book_borrow != "" && ar[i].user_name != "") {
      cout << i + 1 << " book --> " << ar[i].book_borrow << "   user --> "
           << ar[i].user_name << endl;
    }
  }
  cin >> j;
  for (int i = 0; i < 100; i++) {
    if (ar[j - 1].book_borrow == arr[i].name) {
      arr[i].count++;
    }
  }

  ar[j - 1].book_borrow = "";
  ar[j - 1].user_name = "";
  cout << "book returned" << endl;
}

void search(books array[], int n) {
  cout << "enter the search name" << endl;
  string search;
  cin >> search;
  for (int z = 0; z < n; z++) {
    if (search == array[z].name) {
      cout << array[z].id << " " << array[z].name << " there is "
           << array[z].count << " copies" << endl;
    }
  }
}