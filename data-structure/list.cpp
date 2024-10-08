#include <iostream>

template <typename T>
typedef struct
{
    T item;
    Node next;
} Node;

template <typename T>
class List
{
    Node<T> first;
    Node<T> last;

    public:
        List()
        {
            first = last = null;
        }

        void add(T value)
        {
            Node<T> new_value = new Node<T>();
            new_value.item = value;
            new_value.next = null;

            if(is_empty())
            {
                first = new_value;
            } else
            {
                last.next = new_value;
            }
        }

        T pop ()
        {

        }

        bool is_empty()
        {
            return first == null;
        }

};
