#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node* next;
};
// Queue class1

class Queue
{
    public:
    int FRONT, REAR, max = 5;
    int queue_array[5];

private:
    
    // Constructor to initialize the queue
    Queue()
    {
        FRONT = -1;
        REAR = -1;
    }

    // 1. Allocate memory for the new node.
    // 2. Assign value to the data field of the new node.
    // 3. Make the next field of the new node point to NULL.
    // 4. If the queue is empty, execute the following steps:
    // a. Make FRONT point to the new node
    // b. Make REAR  point to the new node
    // d. Exit
    // 5. Make the next field of REAR point to the new node.
    // 6. Make REAR point to the new node.

    // LENGKAPI FUNGSI INI SESUAI ALOGORITMA DIATAS
    void insert()
    {
        int num;
        cout << "Enter a number :";
        cin >> num;
        cout << endl;

        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overFlow\n";
            return;
        }
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        queue_array[REAR] = num;

    }

    //1. If the queue is empty: // FRONT = NULL
        // a. Display “Queue empty”
        // b. Exit
    //2. Mark the node marked FRONT as current
    //3. Make FRONT point to the next node in its sequence
    //4. Release the memory for the node marked as current

    // LENGKAPI FUNGSI INI SESUAI ALOGORITMA DIATAS
    void deleteQueue()
    {
         // cek apakah antrian kosong
     if (FRONT == -1) {
        cout << "Queue underflow\n";
        //cek jika antrian hanya memiliki satu elemen
         if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
          }
          else {
            //jika elemen yang di hapus berada di posos terakhir array, kembali ke awal array
        if (FRONT == max - 1)
             FRONT == 0;
          else
            FRONT = FRONT + 1;
          }
        }
    }
        
    // Function to display all elements of the queue
    void display()
    {   
        int FRONT_position = FRONT;
        int REAR_position = FRONT;

        //cek apakah antrian kosong        
        if (FRONT == -1) {
            cout << "Queue is empty\n";


        }
        // jika FRONT_poostition <= REAR_postition, iterai dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            //jika FRONT_position >REAR_postition, iterasi dari FRONT hingga akhri array
            while (FRONT_position <= max - 1) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            FRONT_position = 0;

            //literasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return FRONT == NULL && REAR == NULL;
    }
};

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.insert();
            break;
        case 2:
            q.deleteQueue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again\n";
        }
    } while (choice != 7);

    return 0;
 }
};
  