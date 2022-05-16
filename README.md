# Command Line Addressbook

The main provides the access to the functionalities provided by the AddressBook class, based on command line parameters.  It can add new
records, list them, remove one by one, find a particular one based on partial matching for name or lastname.

The AddressBook class is based on vector<> template class from stdc++14.  At the end is just that and relies heavily on what the vector template
can do or not.  It is quite straightforward.

The main program runs and load all the records in memory, operates on a standard vector structure, and it stores everything back to a file.
Althgough, this is not very efficient for a large number of records, it does behave like an in-memory database, hence it is very quick.
For large files, it may move towards the realm of databases so it is important to use new approaches to deal with large registers.  We can start
by fixing each record as a fixed-length, creates an index of the file, and use the index to traverse the file.

# Compiling

```bash
make
```

# Testing

```bash
make testcase TC=[nn]
```
where [nn] is the test case number, available in src/tests/.

Currently the infrastructure to create more tests is in place, but there are only two tests:

TC=102.  -  Creates an entry on the addressbook, find it and verify if it exists.

TC=103.  -  Creates two threads that access concurrently the same addressbook, adding and deleting elements.

# Running

```bash
 ./addressbook
 ./addressbook -add -name NAME -last LASTNAME -phone PHONENUMBER
 ./addressbook -remove ENTRYNUMBER
 ./addressbook -search NAME/LASTNAME/
 ./addressbook -lastsort
 ./addressbook -namesort
```

