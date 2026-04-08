template<typename T>
class ArrayList {
    private:
        T * data;
        int numElements;
        int capacity;

        void ensureCapacity();

    public:
        ArrayList(int size);

        ~ArrayList();

        /* we should have a copy constructor and operator= defined here too */

        void add(T t);

        int size();

        T & operator[](const int & idx);
};

