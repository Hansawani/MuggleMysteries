#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Book structure
class Book {
public:
    string title;
    string author;
    string genre;
    float rating;
    int pageCount;
    Book() {}
    Book(string title, string author, string genre, float rating, int pageCount)
    {
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->rating = rating;
        this->pageCount = pageCount;
    }
};

// Book Database class
class Database {
public:
    unordered_map<string, Book> books;
    void addBook(Book newBook);
    Book getBook(const string& title);
    void displayByGenre();
    void displayByAuthor();
    void searchBooksByGenre(const string& genre);
    void searchBooksByAuthor(const string& author);

};

void Database::addBook(Book newBook)
{
    books[newBook.title] = newBook;
}

Book Database::getBook(const string& title)
{
    if (books.find(title) != books.end()) {
        return books[title];
    } else {
        cout << "Book with title '" << title << "' not found." << endl;
        return Book();
    }
}

void Database::searchBooksByGenre(const string& genre)
{
    cout << "Books in the genre '" << genre << "':" << endl;
    for (const auto& pair : books) {
        if (pair.second.genre == genre) {
            cout << pair.second.title << " by " << pair.second.author << endl;
        }
    }
    cout << endl;
}

void Database::searchBooksByAuthor(const string& author)
{
    cout << "Books by the author '" << author << "':" << endl;
    for (const auto& pair : books) {
        if (pair.second.author == author) {
            cout << pair.second.title << " in the genre " << pair.second.genre << endl;
        }
    }
    cout << endl;
}
void Database::displayByGenre()
{

    int ch=1;
    while(ch!=0)
    {
        cout<<"Chose the genre you want to explore:"<<endl;
        cout<<"1.Mystery"<<endl;;
        cout<<"2.Romance"<<endl;
        cout<<"3.Science Fiction"<<endl;
        cout<<"4.Fantasy"<<endl;
        cout<<"5.Horror"<<endl;
        cout<<"6.Historical"<<endl;
        cout<<"7.Thriller"<<endl;
        cout<<"8.Classics"<<endl;
        cout<<"9.Poetry"<<endl;
        cout<<"10.Self Help"<<endl;
        cout<<"0.Exit menu"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;

        switch (ch)
        {
            case 0:
                break;
            case 1:
                {
                    searchBooksByGenre("Mystery");
                    break;
                }
            case 2:
                {
                    searchBooksByGenre("Romance");
                    break;
                }
            case 3:
                {
                    searchBooksByGenre("Science Fiction");
                    break;
                }
             case 4:
                {
                    searchBooksByGenre("Fantasy");
                    break;
                }
            case 5:
                {
                    searchBooksByGenre("Horror");
                    break;
                }
            case 6:
                {
                    searchBooksByGenre("Historical");
                    break;
                }
            case 7:
                {
                    searchBooksByGenre("Thriller");
                    break;
                }
            case 8:
                {
                    searchBooksByGenre("Classics");
                    break;
                }
            case 9:
                {
                    searchBooksByGenre("Poetry");
                    break;
                }
             case 10:
                {
                    searchBooksByGenre("Self Help");
                    break;
                }
             default:
                cout<<"Please enter a valid number";
                break;

            }
    }
}
void Database::displayByAuthor()
{

    int ch=1;
    while(ch!=0)
    {
        cout<<"Chose the author whose book you want to explore:"<<endl;
        cout<<"1. Agatha Christie"<<endl;;
        cout<<"2. Ana Huang"<<endl;
        cout<<"3. Dan Brown"<<endl;
        cout<<"4. J K Rowling"<<endl;
        cout<<"5. Stephen King"<<endl;
        cout<<"6. Charles Dickens"<<endl;
        cout<<"7. Paula Hawkins"<<endl;
        cout<<"8. Jane Austen"<<endl;
        cout<<"9. Sylvia Path"<<endl;
        cout<<"10. Mark Manson"<<endl;
        cout<<"0.Exit menu"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;

        switch (ch)
        {
            case 0:
                break;
            case 1:
                {
                    searchBooksByAuthor("Agatha Christie");
                    break;
                }
            case 2:
                {
                    searchBooksByAuthor("Ana Huang");
                    break;
                }
            case 3:
                {
                    searchBooksByAuthor("Dan Brown");
                    break;
                }
             case 4:
                {
                    searchBooksByAuthor("J K Rowling");
                    break;
                }
            case 5:
                {
                    searchBooksByAuthor("Stephen King");
                    break;
                }
            case 6:
                {
                    searchBooksByAuthor("Charles Dickens");
                    break;
                }
            case 7:
                {
                    searchBooksByAuthor("Paula Hawkins");
                    break;
                }
            case 8:
                {
                    searchBooksByAuthor("Jane Austen");
                    break;
                }
            case 9:
                {
                    searchBooksByAuthor("Sylvia Path");
                    break;
                }
             case 10:
                {
                    searchBooksByAuthor("Mark Manson");
                    break;
                }
             default:
                cout<<"Please enter a valid number";
                break;

            }

    }
}
class ReadingListNode
 {
public:
    string ReadingListName;
    vector <string> bookNames;
    ReadingListNode *left;
    ReadingListNode *right;
    ReadingListNode(){}
    ReadingListNode(string rl_name)
     {
        ReadingListName=rl_name;
        left=right=NULL;

     }

 };
class ReadingListTree
{
public:
    ReadingListNode *root;
    ReadingListTree()
    {
        root = NULL;
    }
    void insertReadingList(ReadingListNode*& root, string rl_name);
    void printLevelOrder(ReadingListNode* root);
    void addBookIntoRL(string bookName, string rl_name);
    void removeBookFromRL(string bookName, string rl_name);
    void getReadingList(ReadingListNode*& root, string rl_name);

};
// Function to add new ReadingListName in level order
void ReadingListTree :: insertReadingList(ReadingListNode*& root, string rl_name)
{
    ReadingListNode* temp = new ReadingListNode(rl_name); // Initialize with ReadingListName
    temp->ReadingListName = rl_name;
    temp->left = temp->right = NULL;
    if (!root)
        root = temp;
    else {
        queue<ReadingListNode*> q;
        q.push(root);
        while (!q.empty()) {
            ReadingListNode* temp = q.front();
            q.pop();
            if (!temp->left)
            {
                temp->left = new ReadingListNode;
                temp->left->ReadingListName = rl_name;
                temp->left->left = temp->left->right = NULL;
                break;
            }
            else
                q.push(temp->left);
            if (!temp->right)
            {
                temp->right = new ReadingListNode;
                temp->right->ReadingListName = rl_name;
                temp->right->left = temp->right->right = NULL;
                break;
            }
            else
                q.push(temp->right);
            }
        }
}

// Function to print Level Order Traversal
void ReadingListTree :: printLevelOrder(ReadingListNode* root) {
    if (root == NULL) return;
    queue<ReadingListNode*> q;
    q.push(root);
    while (!q.empty()) {
        ReadingListNode* node = q.front();
        cout << node->ReadingListName << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
        }
}
void ReadingListTree :: addBookIntoRL(string bookName, string rl_name)
{
    if (root == NULL) return;
    queue<ReadingListNode*> q;
    q.push(root);
    while (!q.empty()) {
        ReadingListNode* node = q.front();
        if (node->ReadingListName == rl_name)
        {
            node->bookNames.push_back(bookName);
            break;
        }
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
        }
}
void ReadingListTree :: removeBookFromRL(string bookName, string rl_name)
{
    if (root == NULL)
        return;
    queue<ReadingListNode*> q;
    q.push(root);
    while (!q.empty()) {
        ReadingListNode* node = q.front();
        if (node->ReadingListName == rl_name)
        {
            auto it = find(node->bookNames.begin(), node->bookNames.end(),
                   bookName);
            if (it != node->bookNames.end()) {
                node->bookNames.erase(it);
            }
            break;
        }
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
        }
}

void ReadingListTree :: getReadingList(ReadingListNode*& root, string rl_name)
{
    if (root == NULL) return;
    queue<ReadingListNode*> q;
    q.push(root);
    while (!q.empty())
        {
        ReadingListNode* node = q.front();
        if (node->ReadingListName == rl_name)
        {
            int n = node->bookNames.size();
            for(int i = 0; i < n; i++)
            {
                cout << node->bookNames[i] << endl;
            }
            break;
        }
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
        }
}
int main()
{
    Database bookDB;
    ReadingListTree RLT;

    Book book1("The Mysterious Affair at Styles", "Agatha Christie", "Mystery", 4.0, 174);
    Book book2("The Secret Adversary", "Agatha Christie", "Mystery", 3.85, 266);
    Book book3("The Murder at the Vicarage", "Agatha Christie", "Mystery", 4.05, 307);
    Book book4("Ask a Policeman", "Agatha Christie", "Mystery", 3.24, 311 );
    Book book5("Murder on the Orient Express", "Agatha Christie", "Mystery", 4.20, 274);

    Book book6("Twisted Love", "Ana Huang","Romance", 3.73, 274);
    Book book7("Twisted Games", "Ana Huang","Romance", 4.13, 456);
    Book book8("King of Wrath", "Ana Huang","Romance",4.07, 398);
    Book book9("King of Pride", "Ana Huang","Romance", 3.98, 358);
    Book book10("King of Greed", "Ana Huang","Romance",3.84 , 352);


    Book book11("Angels & Demons", "Dan Brown","Science Fiction", 3.94, 736);
    Book book12("Digital Fortress", "Dan Brown","Science Fiction", 3.69, 274);
    Book book13("The Da Vinci Code", "Dan Brown","Science Fiction", 3.91, 510);
    Book book14("Origin", "Dan Brown","Science Fiction", 3.89, 461);
    Book book15("Deception Point", "Dan Brown","Science Fiction", 3.75, 556);


    Book book16("Harry Potter and the Philosopher's Stone", "J K Rowling", "Fantasy", 4.5, 333);
    Book book17("Harry Potter and the Chamber of Secrets", "J K Rowling", "Fantasy", 4.43, 341);
    Book book18("Harry Potter and the Prisoner of Azkaban", "J K Rowling", "Fantasy", 4.58, 435);
    Book book19("Harry Potter and the Goblet of Fire", "J K Rowling", "Fantasy", 4.56, 734);
    Book book20("Harry Potter and the Order of the Phoenix", "J K Rowling", "Fantasy", 4.5, 912);
    Book book21("Harry Potter and the Half-Blood Prince", "J K Rowling", "Fantasy", 4.58, 652);
    Book book22("Harry Potter and the Deathly Hallows", "J K Rowling", "Fantasy", 4.62, 759);


    Book book23("It", "Stephen King", "Horror", 4.25, 1168);
    Book book24("Misery", "Stephen King", "Horror", 4.21, 370);
    Book book25("The Shining", "Stephen King", "Horror", 4.26, 497);
    Book book26("Carrie", "Stephen King", "Horror", 3.98, 272);
    Book book27("The Green Mile", "Stephen King", "Horror", 4.47, 592);
    Book book28("Angels & Demons", "Dan Brown","Science Fiction", 3.94, 736);

    Book book29("Dombey and Son", "Charles Dickens","Historical", 3.95, 736);
    Book book30("Oliver Twist", "Charles Dickens","Historical", 3.88, 608);
    Book book31("Bleak House", "Charles Dickens","Historical", 4.01, 1017);
    Book book32("Little Dorrit", "Charles Dickens","Historical", 4.0, 1021);
    Book book33("A Tale of Two Cities", "Charles Dickens","Historical", 3.87, 489);

    Book book34("The Girl on the Train", "Paula Hawkins", "Thriller", 3.96, 336);
    Book book35("Into the Water", "Paula Hawkins", "Thriller", 3.59, 386);
    Book book36("A Slow Fire Burning", "Paula Hawkins", "Thriller", 3.5, 307);


    Book book37("The Bell Jar", "Sylvia Path", "Poetry", 4.05, 244);
    Book book38("Ariel", "Sylvia Path", "Poetry", 4.20, 128);


    Book book39("Pride and Prejudice", "Jane Austen", "Classics", 4.28, 279);
    Book book40("Sense and Sensibility", "Jane Austen", "Classics", 4.08, 409);
    Book book41("Emma", "Jane Austen", "Classics", 4.04, 474);
    Book book42("Persuasion", "Jane Austen", "Classics", 4.15, 249);
    Book book43("Northanger Abbey", "Jane Austen", "Classics", 3.85, 260);

    Book book44("The Subtle Art of Not Giving a F*ck", "Mark Manson", "Self Help", 3.9, 212);
    Book book45("Everything is F*cked", "Mark Manson", "Self Help", 3.7, 288);
    Book book46("The Nerd's Guide to Being Confident", "Mark Manson", "Self Help", 3.63, 63);
    Book book47("3 Ideas That Can Change Your Life", "Mark Manson", "Self Help", 4.1, 23);
    Book book48("Mark Manson on Self-Knowledge", "Mark Manson", "Self Help", 4.15, 24);

    bookDB.addBook(book1);
    bookDB.addBook(book2);
    bookDB.addBook(book3);
    bookDB.addBook(book4);
    bookDB.addBook(book5);
    bookDB.addBook(book6);
    bookDB.addBook(book7);
    bookDB.addBook(book8);
    bookDB.addBook(book9);
    bookDB.addBook(book10);
    bookDB.addBook(book11);
    bookDB.addBook(book12);
    bookDB.addBook(book13);
    bookDB.addBook(book14);
    bookDB.addBook(book15);
    bookDB.addBook(book16);
    bookDB.addBook(book17);
    bookDB.addBook(book18);
    bookDB.addBook(book19);
    bookDB.addBook(book20);
    bookDB.addBook(book21);
    bookDB.addBook(book22);
    bookDB.addBook(book23);
    bookDB.addBook(book24);
    bookDB.addBook(book25);
    bookDB.addBook(book26);
    bookDB.addBook(book27);
    bookDB.addBook(book28);
    bookDB.addBook(book29);
    bookDB.addBook(book30);
    bookDB.addBook(book31);
    bookDB.addBook(book32);
    bookDB.addBook(book33);
    bookDB.addBook(book34);
    bookDB.addBook(book35);
    bookDB.addBook(book36);
    bookDB.addBook(book37);
    bookDB.addBook(book38);
    bookDB.addBook(book39);
    bookDB.addBook(book40);
    bookDB.addBook(book41);
    bookDB.addBook(book42);
    bookDB.addBook(book43);
    bookDB.addBook(book44);
    bookDB.addBook(book45);
    bookDB.addBook(book46);
    bookDB.addBook(book47);
    bookDB.addBook(book48);
    int ch=0;
    while(ch!=7)
    {
        cout<<"\nChoose what you want to do:"<<endl;
        cout<<"1.Add to reading list."<<endl;
        cout<<"2.Remove from list."<<endl;
        cout<<"3.Display reading list."<<endl;
        cout<<"4.Recommend book."<<endl;
        cout<<"5.Display book information."<<endl;
        cout<<"6.Create new reading list."<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            cin.ignore();
            string rlname;
            cout<<"Your existing reading lists are:"<<endl;
            RLT.printLevelOrder(RLT.root);
            cout<<endl;
            cout<<"Enter name of reading list you want to add a book to:";
            getline(cin,rlname);
            int ch;
            cout<<"Show books by 1.Author 2.Genre :";
            cin>>ch;
            if(ch==1)
            {
                bookDB.displayByAuthor();
                string bname;
                cout<<"Enter which book you want to add to your list: ";
                getline(cin,bname);
                RLT.addBookIntoRL(bname,rlname);
            }
            else if(ch==2)
            {
                bookDB.displayByGenre();
                string bname;
                cout<<"Enter which book you want to add to your list:";
                getline(cin,bname);
                RLT.addBookIntoRL(bname,rlname);
            }
            else
                cout<<"Invalid choice.";
            break;
        }

        case 2:
        {
            cin.ignore();
            cout<<"Your existing reading lists are:"<<endl;
            RLT.printLevelOrder(RLT.root);
            string rlname;
            cout<<"Enter which reading list you want to remove from:";
            getline(cin,rlname);
            cout<<"Here's your chosen reading list:"<<endl;
            RLT.getReadingList(RLT.root,rlname);
            string bname;
            cout<<"Enter which book you want to remove from your list:";
            getline(cin,bname);
            RLT.removeBookFromRL(bname,rlname);
            break;
        }

        case 3:
        {
            cin.ignore();
            cout<<"Your existing reading lists are:"<<endl;
            RLT.printLevelOrder(RLT.root);
            string rlname;
            cout<<"Enter which reading list you want to display:";
            getline(cin,rlname);
            cout<<"Here's your chosen reading list:"<<endl;
            RLT.getReadingList(RLT.root,rlname);
            break;
        }

        case 4:
        {
            cin.ignore();
            int ch;
            cout<<"Do you want recommendations based on 1.Author 2.Genre ?";
            cin>>ch;
            if(ch==1)
            {
                bookDB.displayByAuthor();
            }
            else if(ch==2)
            {
                bookDB.displayByGenre();
            }
            else
                cout<<"Invalid choice.";
            break;
        }

        case 5:
        {
            cin.ignore();
            string bname;
            cout<<"Enter book name whose information is needed:";
            getline(cin,bname);
            bookDB.getBook(bname);
            break;
        }

        case 6:
        {
            cin.ignore();
            string rlname;
            cout<<"Enter name of new reading list:";
            getline(cin,rlname);
            RLT.insertReadingList(RLT.root,rlname);
            break;
        }

        case 7:
            break;

        default:
            cout<<"Please enter a valid number";
            break;
        }
    }
    return 0;
}
