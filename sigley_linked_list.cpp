#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class ll
{
public:
    node *head = NULL;
    void addInBeg(int val)
    {
        node *temp = new node;
        temp->data = val;
        if (head == NULL)
        {
            temp->next = NULL;
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void addInLast(int val)
    {
        node *temp = new node;
        temp->data = val;
        if (head == NULL)
        {
            head = temp;
            temp->next = NULL;
        }
        else
        {
            node *n = new node;
            n = head;
            while (n->next != NULL)
            {
                n = n->next;
            }
            n->next = temp;
            temp->next = NULL;
        }
    }
    void addInSpecPos(int pos, int value)
    {
        node *pre = new node;
        node *cur = new node;
        node *temp = new node;
        cur = head;
        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        temp->data = value;
        pre->next = temp;
        temp->next = cur;
    }
    void delFromFront()
    {
        node *temp = new node;
        temp = head;
        if (head == NULL)
            cout << "nothing to delete";
        else
        {
            head = temp->next;
        }
    }
    void delFromEnd()
    {
        node *cur = new node;
        node *prev = new node;
        cur = prev = head;
        if (head == NULL)
            cout << "not possible";
        else
        {
            cur = cur->next;
            while (cur->next != NULL)
            {
                prev = prev->next;
                cur = cur->next;
            }
            prev->next = NULL;
        }
    }
    void delFromSpecPos(int pos)
    {
        if (pos == 1)
            delFromFront();
        else
        {
            node *prev = new node;
            node *cur = new node;
            cur = prev = head;
            cur = cur->next;
            cur = cur->next;
            for (int i = 1; i < pos - 1; i++)
            {
                cur = cur->next;
                prev = prev->next;
            }
            prev->next = cur;
        }
    }
    void search(int value)
    {
        node *temp = new node;
        temp = head;
        int i = 0, j = 0;
        while (temp != NULL)
        {
            i++;
            if (temp->data == value)
            {
                j++;
                cout << endl
                     << "data is in the position" << i << endl;
            }
            temp = temp->next;
        }
        if (j == 0)
            cout << "not present" << endl;
    }
    void display()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << '\t';
            temp = temp->next;
        }
    }
};
int main()
{
    class ll a;
    int n, b, p;
    cout << "       ENTER YOUR CHOICE" << endl;
    cout << "       1. for adding value from front" << endl;
    cout << "       2. for adding value from end" << endl;
    cout << "       3. for adding value from specific position" << endl;
    cout << "       4. for deleting value from front" << endl;
    cout << "       5. for deleting value from end" << endl;
    cout << "       6. for deleting value from specific position" << endl;
    cout << "       7. for searching a value" << endl;
    cout << "       8. for displaying all the value" << endl;
    cout << "       0. for ending the program" << endl;
    cin >> n;
    while (n != 0)
    {

        if (n == 1)
        {
            cout << "enter value to be added" << endl;
            cin >> b;
            a.addInBeg(b);
        }
        else if (n == 2)
        {
            cout << "enter value to be added" << endl;
            cin >> b;
            a.addInLast(b);
        }
        else if (n == 3)
        {
            cout << "enter position and value to be added" << endl;
            cin >> p >> b;
            a.addInSpecPos(p, b);
        }
        else if (n == 4)
        {
            cout << "deleting from front" << endl;
            a.delFromFront();
        }
        else if (n == 5)
        {
            cout << "deleting from end" << endl;
            a.delFromEnd();
        }
        else if (n == 6)
        {
            cin >> p;
            cout << "deleted from specific position " << endl;
            a.delFromSpecPos(p);
        }
        else if (n == 7)
        {
            cin >> p;
            a.search(p);
        }
        else if (n == 8)
        {
            a.display();
        }
        else
            cout << "please try the suggested option";
        cin >> n;
        if (n == 0)
            cout << "ending the program";
    }
    return 0;
}
