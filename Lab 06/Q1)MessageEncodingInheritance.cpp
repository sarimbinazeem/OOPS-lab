#include <iostream>
#include <string>
using namespace std;

class Message
{
	protected:
	    string text;
	
	public:
	
	    Message() 
		{
			
		}
	
	    Message(string text)
	    {
	        this->text = text;
	    }
	
	    string toString() const
	    {
	        return text;
	    }
	
	    void setText(string text)
	    {
	        this->text = text;
	    }
	};

class SMS : public Message
{
	private:
	    string recipientContactNo;
	
	public:
	
	    SMS(string text, string contact) : Message(text)
	    {
	        recipientContactNo = contact;
	    }
	
	    string getContact()
	    {
	        return recipientContactNo;
	    }
	
	    void setContact(string contact)
	    {
	        recipientContactNo = contact;
	    }
	
	    string toString() const
	    {
	        return text + " " + recipientContactNo;
	    }
	
	    void display()
	    {
	        cout << "SMS: " << toString() << endl;
	    }
};

class Email : public Message
{
private:
    string sender;
    string receiver;
    string subject;

public:

    Email(string text,string sender,string receiver,string subject) : Message(text)
    {
        this->sender = sender;
        this->receiver = receiver;
        this->subject = subject;
    }

    string getSender()
    {
        return sender;
    }

    string getReceiver()
    {
        return receiver;
    }

    string getSubject()
    {
        return subject;
    }

    void setSender(string sender)
    {
        this->sender = sender;
    }

    void setReceiver(string receiver)
    {
        this->receiver = receiver;
    }

    void setSubject(string subject)
    {
        this->subject = subject;
    }

    string toString() const
    {
        return text + " " + sender + " " + receiver + " " + subject;
    }

    void display()
    {
        cout << "Email: " << toString() << endl;
    }
};

bool ContainsKeyword(const Message& messageObject, const string& keyword)
{
    if(messageObject.toString().find(keyword) != -1)
    {
        return true;
    	
	}

    return false;
}

string encoding(const Message& msg)
{
    string message = msg.toString();

    for(int i = 0; i < message.length(); i++)
    {
        if(message[i] >= 'A' && message[i] <= 'Y')
        {
            message[i]++;
        	
		}

        else if(message[i] == 'Z')
        {
            message[i] = 'A';
        	
		}

        else if(message[i] >= 'a' && message[i] <= 'y')
        {
            message[i]++;
        	
		}

        else if(message[i] == 'z')
        {
        	
            message[i] = 'a';
		}
    }

    return message;
}

int main()
{
    SMS s("FREE UFONE BALANCE! 500 MBs","03361251259");

    cout << "\n==SMS==\n";
    s.display();
	
	string keyword;
	cout<<"Enter A KeyWord To Find In String: ";
	cin>>keyword;
	
    if(ContainsKeyword(s,keyword))
    {
        cout << "Keyword "<<keyword<<" Found\n"; 	
	}
	else
	{
        cout << "Keyword "<<keyword<<" Not Found\n";
		
	}

    cout << "\n===Encoded SMS===\n";
    cout << encoding(s) << endl;
    
    Email e("Extra Class in Lab 01 of OOP Lab","Izzah Salam","Sarim Bin Azeem","Extra Class");

    cout << "\n==Email==\n";
    e.display();
	
	cout<<"Enter A KeyWord To Find In Email: ";
	cin>>keyword;
	
    if(ContainsKeyword(e,keyword))
    {
        cout << "Keyword "<<keyword<<" Found\n"; 	
	}
	else
	{
        cout << "Keyword "<<keyword<<" Not Found\n";
		
	}

    cout << "\n===Encoded Email===\n";
    cout << encoding(e) << endl;

    return 0;
}