/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   18-Apr-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: test2.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 18-Apr-2021
 */

/*
   Write a program to create the following Office Pay Roll System. The following menu will always be displayed except if exited by pressing ‘q’.



   ======= Office Pay Roll System =========

   • Enter ‘a’, to take salary of all employees into “salary” array of size N.

   • Enter ‘b’, to find the average salary of all employees.

   • Enter ‘c’, to count and display the # of employees who have above average salary.

   • Enter ‘q’, to quit/exit the menu system.

   • For any other input, display “Invalid Input.”



   After the menu is displayed, the program will prompt the user “Enter your choice: “ to enter a choice from the menu. After user enters his choice, the program will act according to the menu choice mentioned above.

   That means, if user enters ‘a’, your program will take salary of all employees into “salary” array from keyboard. If user enters ‘c’, it will count and display the # of employees who have above average salary. For choice ‘c’, it also needs to compute the average salary of all employees. For choices ‘b’ and ‘c’, the program needs to check whether salary of all employees are already populated into “salary” array or not. If not populated, it will display “No salary information is found”. Please populate your salary information first.” Use switch case to handle the choice options. Do not use library functions to find average.
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

int main()
{

        int N,avg = 0,count = 0,sum = 0;

        char input;

        printf("Enter Array Size\n");

        scanf("%d",&N);

        int arr[N] = {0};

        printf("Enter a to take salary of all employee\n");
        printf("Enter b to find average salary of employee\n");
        printf("Enter c to count and display the number of employees who have above average salary\n");
        printf("Enter q to quit/exit menu\n");

        std::cin >> input;

        switch (input) {
        case 'a':
                for (int i = 0; i < N; i++)
                {
                        scanf("%d", &arr[i]);
                }
        default:
                std::cout << "Invalid Input." << '\n';
        }

        std::cin >> input;
        switch (input) {
        case 'b':
                for (int i = 0; i < N; i++)
                {

                        sum += arr[i];
                }
                avg = sum/N;
                std::cout << "Avarage of salary is: " << avg << '\n';

        default:
                std::cout << "Invalid Input." << '\n';
        }

        std::cin >> input;
        switch (input) {
        case 'c':
                for (int i = 0; i < N; i++)
                {
                        if(arr[i]>avg) {
                                count++;
                                printf("Count = %d\nEmployee %d above average salary\n",count,i+1);
                        }
                }
        default:
                std::cout << "Invalid Input." << '\n';
        }

        std::cin >> input;
        switch (input) {
        case 'q':
                break;
        default:
                std::cout << "Invalid Input." << '\n';
        }
}
