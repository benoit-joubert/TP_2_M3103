#include <iostream>
#include <node.hpp>
#include <list.hpp>
using namespace std;

void ListeSimpleV2 ()
{
    cout << "ListeSimpleV2 : \n\n";

    CList<int> AList;

    // Le dernier element cree est toujours le premier de la liste

    for (unsigned i (0); i < 5; )
    {
        AList.push_front (i++);
    }

    AList.Show ();

    int i;
    cin >>i;
    CNode<int>* ptr = AList.Find (i);
    AList.Add (3*i, ptr);
    AList.Show ();

    cout << ((ptr != NULL)?  " " : "non ") << "trouve" << endl;

    AList.Show();
    int j;
    cin >>j;
    AList.push_back(j);
    AList.Show();

}

int main()
{
    ListeSimpleV2();
    return 0;
}
