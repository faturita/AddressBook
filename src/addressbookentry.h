#include <stdio.h>
#include <string.h>

#include <vector>
#include <mutex>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <regex>

#include "commandline.h"

#ifndef ADDRESSBOOKENTRY_H
#define ADDRESSBOOKENTRY_H

#define DELIMITER "/"

enum SORT { NAMESORT=1, LASTNAMESORT=2};

class AddressBookEntry
{
    std::string Name;
    std::string LastName;
    std::string phoneNumber;

    //
    //  We can add here a blob-like in base64 to store images
    //
    //  std::string image
    //
    //  We can then convert images to base64 blobs and store them here in the same way as the other parameters.
    //  I am using "/" as delimiter which IS used in base64 so I will have to use a differnt value for that.


public:
    AddressBookEntry();

    AddressBookEntry(std::string name, std::string lastname, std::string phone);

    std::string toString() const;

    // Encode the data to store it --->   NAME/LAST/PHONE/    (trailing slash)
    std::string serialize() const;

    // Decode it
    void deserialize(std::string code);

    std::string comp(int sorttype);

    std::string GetName();

    std::string GetLastName();

    bool operator==(AddressBookEntry ad);


};

#endif // ADDRESSBOOKENTRY_H
