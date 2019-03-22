#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Matrix
{
  public:
    int a;
    int b;

  public:
    Matrix() {}
    Matrix(int a, int b) : a(a), b(b) {}
};
int main()
{
    int n;
    cin >> n;
    Matrix matrice[26];

    int a, b;
    for (int i = 0; i < n; i++)
    {
        char name;
        cin >> name >> a >> b;
        matrice[name - 'A'] = Matrix(a, b);
    }

    string expr;
    while (cin >> expr)
    {
        // cout << expr << endl;
        int ans = 0;
        bool error = false;
        stack<Matrix> s;
        for (auto p : expr)
        {
            if (isalpha(p))
            {
                s.push(matrice[p - 'A']);
            }
            else if (p == ')')
            {
                Matrix m2 = s.top();
                s.pop();
                Matrix m1 = s.top();
                s.pop();
                if (m1.b != m2.a)
                {
                    error = true;
                    break;
                }
                ans += m1.a * m1.b * m2.b;
                s.push(Matrix(m1.a, m2.b));
            }
        }
        if (error)
            cout << "error\n";
        else
            cout << ans << endl;
    }

    return 0;
}