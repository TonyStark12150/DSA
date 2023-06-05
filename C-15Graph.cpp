
/*
You have a business with several offices; you want to lease phone lines to connect them
up with each other; and the phone company charges different amounts of money to
connect different pairs of cities. You want a set of lines that connects all your offices with
a minimum total cost. Solve the problem by suggesting appropriate data structures. 
*/

#include<iostream>
#define MAX 10
using namespace std;

class graph {
    int from[MAX], visited[MAX], dist[MAX];
    int a[MAX][MAX], b[MAX][MAX], n, e;

public:
    graph() {
        for (int i = 0; i < MAX; i++) {
            visited[i] = 0;
            dist[i] = 1000;
        }
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                b[i][j] = 0;
            }
        }
    }

    void input(int n) {
        int val;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cout << "Enter cost from office " << i + 1 << " to office " << j + 1 << " (0 if not):" << endl;
                cin >> val;
                a[i][j] = val;
                a[j][i] = a[i][j];
            }
        }
        cout << "Input Matrix is as :" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    void prims(int n) {
        int u, v, sum;
        sum = 0;
        int cost[MAX][MAX];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0)
				{
                    cost[i][j] = 100;
                }
				else
				{
                    cost[i][j] = a[i][j];
                }
            }
        }
        visited[0] = 1;
        for (int i = 1; i < n; i++) {
            dist[i] = cost[0][i];
            from[i] = 0;
        }

        e = n - 1;
        while (e >= 0) {
            int mindist = 100;
            for (int i = 1; i < n; i++) {
                if (dist[i] < mindist && visited[i] == 0) {
                    mindist = dist[i];
                    v = i;
                }
            }
            u = from[v];
            b[u][v] = cost[u][v];
            b[v][u] = cost[v][u];

            sum = sum + cost[u][v];
            cout << "SUM=" << sum << endl;
            e--;
            visited[v] = 1;

            for (int i = 1; i < n; i++) {
                if (dist[i] > cost[v][i] && visited[i] == 0) {
                    dist[i] = cost[v][i];
                    from[i] = v;
                }
            }
        }

        cout << "Minimum cost is " << sum << endl;
    }

    void display(int n) {
        cout << "Output Matrix :" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of offices: ";
    cin >> n;
    graph g;
    g.input(n);
    g.prims(n);
    g.display(n);
    return 0;
}

		
		
