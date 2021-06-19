/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   06-Jun-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: hash_chain.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 06-Jun-2021
 */

#include "bits/stdc++.h"

using namespace std;
#define el "\n"
#define F first
#define S second
#define PI 3.14159265358979323846  /* pi */
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define SQR(x) (x)*(x)
#define all(v)    ((v).begin()),((v).end())
#define degreesToRadians(angleDegrees) (angleDegrees * PI / 180.0) // Converts degrees to radians.
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / PI) // Converts radians to degrees.
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pll;
typedef long double ld;
typedef vector<int>   vi;
typedef vector<ll>    vll;
typedef vector<pii>   vpii;
typedef vector<pll>   vpll;
const double EPS = 1e-9;
const int N = 1e3+2, M = 3e5+5, OO = 0x3f3f3f3f;
// int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; // 4 Direction
// int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1}; // 8 Direction
// int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; // Knight Direction
// int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; // Hexagonal Direction

#define M 100
#define NULL 0

class Object {
public:
char key[100];
int value;

Object() {

}
Object(const char k[], int v) {
        strcpy(key, k);
        value = v;
}
};

class Node {
public:
Object data;
Node* next;
};

class LinkedList {
Node* head;

public:
LinkedList() {
        head = NULL;
}

void insert(Object o) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = o;
        newNode->next = head;
        head = newNode;
}

int search(const char k[]) {
        Node* temp = head;
        while(temp != NULL) {
                if(strcmp(temp->data.key, k) == 0) {
                        return temp->data.value;
                }
                temp = temp->next;
        }
        return -1;
}
};

class HashTable {
LinkedList Table[M];

public:
HashTable() {

}

int h_aux(const char k[]) {
        int sum=0;
        int len = strlen(k);
        for(int i=0; i<len; i++) {
                sum = sum + k[i];
        }
        return sum%M;
}

int h(const char k[]) {
        return (2*h_aux(k) + 5)%M;
}

void insert(const char k[], int v) {
        int j = h(k);
        Object o(k, v);
        Table[j].insert(o);
}

int search(const char k[]) {
        int j = h(k);
        return Table[j].search(k);
}
};

int main() {

        HashTable T;

        T.insert("a", 1);
        T.insert("b", 5);
        T.insert("c", 189);

        printf("%d\n", T.search("a"));
        printf("%d\n", T.search("b"));
        printf("%d\n", T.search("c"));

        return 0;
}


