#include <iostream>
#include <fstream>
#include <algorithm>

#define INITIAL_CAPACITY 16

template<typename T>
class medianSet
{
public:
    medianSet()
    {
        data = new T[INITIAL_CAPACITY];
        this->size = INITIAL_CAPACITY;
        index = 0;
    }

    ~medianSet()
    {
        delete[] data;
        data = NULL;
    };

    void insert(T number)
    {
        if(index + 1 > this->size)
        {
            resizeSet();
        }
        data[index] = number;

        if(index > 1)
        {
            // O(n) time complexity for each insertion of new element
            insertElementAtPlace();
        }
        this->index++;
    }

    double getMedian()
    {
        // even count of numbers in set
        if(index % 2 == 0)
        {
            return static_cast<double>( data[(index / 2) - 1] + data[index / 2] ) / 2;
        }

        // odd count of numbers in set
        if(index % 2 != 0)
        {
            return static_cast<double>(data[index / 2]);
        }

        return 0.0f;
    }
private:
    medianSet(const medianSet&) {};
    medianSet& operator=(const medianSet&) {};
private:
    void resizeSet()
    {
        // allocate temp buffer to copy the data
        T * temp = new T[this->size];
        for(uint32_t i = 0; i < this->size; i++)
        {
            temp[i] = data[i];
        }

        delete[] data;
        data = NULL;
        data = new T[this->size * 2];

        // reallocate the data
        for(uint32_t i = 0; i < this->size; i++)
        {
            data[i] = temp[i];
        }
        // double the size of the container
        this->size = this->size * 2;

        delete[] temp;
        temp = NULL;
    }

    void insertElementAtPlace()
    {
        // if last added element is biggest don't perform insertion
        if(data[index] > data[index - 1])
        {
            return;
        }
        for(int i = this->index; i > 0; i--)
        {
            if(data[i] < data[i - 1])
            {
                std::swap(data[i], data[i - 1]);
            }
        }
    }

private:
    T * data;
    uint32_t index;
    uint32_t size;
};


int main()
{
    medianSet<int> median;
#if 0
    median.insert(7);
    median.insert(1);
    median.insert(6);
    median.insert(3);
    median.insert(9);
    median.insert(3);
    median.insert(8);
#endif

#if 0
    median.insert(1);
    median.insert(2);
    median.insert(3);
    median.insert(4);
    median.insert(5);
    median.insert(6);
    median.insert(8);
    median.insert(9);
#endif

#if 1
    median.insert(8);
    median.insert(14);
    median.insert(8);
    median.insert(45);
    median.insert(1);
    median.insert(31);
    median.insert(16);
    median.insert(40);
    median.insert(30);
    median.insert(24);
    median.insert(42);
    median.insert(30);
    median.insert(12);
#endif


#if 0
    median.insert(4);
    median.insert(1);
    median.insert(6);
    median.insert(3);
    median.insert(9);
    median.insert(3);
    median.insert(7);
    median.insert(1);
    median.insert(2);
    median.insert(1);
    median.insert(1);
    median.insert(1);
    median.insert(1);
    median.insert(1);
#endif

#if 0
    median.insert(48);
    median.insert(-6);
    median.insert(-6);
    median.insert(28);
    median.insert(2);
    median.insert(-37);
    median.insert(-36);
    median.insert(-34);
#endif

#if 0
    median.insert(1);
    median.insert(3);
    median.insert(5);
    median.insert(7);
    median.insert(2);
#endif

#if 0
    median.insert(31);
    median.insert(27);
    median.insert(93);
    median.insert(92);
    median.insert(80);
    median.insert(96);
    median.insert(48);
    median.insert(4);
    median.insert(92);
#endif

#if 0
    median.insert(9);
    median.insert(9);
    median.insert(9);
    median.insert(9);
#endif

#if 0
    std::string file = "test_case_10000.txt";
    std::ifstream inFile;
    inFile.open(file.c_str());

    if (inFile.is_open())
    {
        int temp = 0;
        for (int i = 0; i < 10000; i++)
        {
            inFile >> temp;
            median.insert(temp);
        }
        inFile.close();
    }
#endif

    std::cout << median.getMedian() << std::endl;
    return 0;
}
