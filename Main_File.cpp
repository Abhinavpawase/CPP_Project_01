
#include "Header.h"

// Abstract Class Example

class Identifiable{
protected:
    string uniqueID;

public:
    Identifiable(const string &id) : uniqueID(id) {
        cout << "Identifiable created : " << uniqueID << endl;
    }

    virtual ~Identifiable() {
        cout << "Identifiable destroyed : " << uniqueID << endl;
    }

    virtual string getID() const { return uniqueID ; }

    virtual void displayIdentity() const {
        cout << "ID : " << uniqueID << endl;
    }

};

class NetworkIdentifiable : public virtual Identifiable {
protected:
    string networkAddress;
public:
    NetworkIdentifiable(const string &id , const string &addr) : 
                            Identifiable(id) , networkAddress(addr) {
        cout << "Network identity established : " << networkAddress << endl;
    }

    virtual ~NetworkIdentifiable() {
        cout << "Network identity cleared : " << networkAddress << endl;
    }

    virtual string getNetworkAddress() const { return networkAddress; }

    void displayIdentity() const override {
        Identifiable::displayIdentity();
        cout << "Network Address : " << networkAddress << endl;
    }

};

class SecureIdentifiable : public virtual  Identifiable {
protected:
    string securityToken;
public:
    SecureIdentifiable(const string &id , const string &token) : 
                            Identifiable(id) , securityToken(token){
        cout << "Security identity established ..." << securityToken.substr(0 , 10) << endl; 
    }

    virtual ~SecureIdentifiable() {
        cout << "Security Identity Cleared..." << endl;
    }

    virtual string getSecurityToken() const { return securityToken; }

    virtual bool validateSecurity() const { return !securityToken.empty(); }

    // void displayIdentity() const override {
    //     Identifiable::displayIdentity();
    //     cout << "Security token : " << securityToken.substr(0 , 10) << endl;
    // }

};

class SecureNetworkDevice : public NetworkIdentifiable , public SecureIdentifiable {
private:
    string deviceName;
    bool secureConnectionActive;
public:
    SecureNetworkDevice(const string &id , const string &name , const string &addr , const string &token) 
                            : Identifiable(id) , NetworkIdentifiable(id , addr) , SecureIdentifiable(id , token) ,
                                deviceName(name) , secureConnectionActive(false) {
        cout << "Secure Network Device Created : " << deviceName << endl;
    }

    ~SecureNetworkDevice() {
        cout << "Secure Network Device Created : " << deviceName << endl;
    }

    void displayIdentity() const override {
        cout << "--- Secure Network Device Identity ---" << endl;
        cout << "Device Name - " << deviceName << endl;
        Identifiable::displayIdentity();
        cout << "Network Address : " << getNetworkAddress() << endl;
        cout << "Security status : " << (validateSecurity() ? "" : "") << endl;
        cout << "Secure Connection : " << (secureConnectionActive ? "VALID" : "INVALID") << endl;
    }

    void establishSecureConnection(){
        if(validateSecurity()){
            secureConnectionActive = true;
            cout << "Secure Connection Established for " << deviceName << endl;
            cout << "Network : " << getNetworkAddress() << endl;
            cout << "Security validated" << endl;
        }else{
            cout << "Secure connection failed - Invalid security token" << endl;
        }
    }

    void terminateConnection(){
        secureConnectionActive = false;
        cout << "secure connection terminated for " << deviceName << endl;
    }

    bool isSecurelyConnected() const {
        return secureConnectionActive && validateSecurity();
    }

    string getDeviceName() const { return deviceName; }

};

int main(){

    

    return 0;
	
}
