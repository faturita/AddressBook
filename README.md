# Command Line Addressbook

The main provides the access to the functionalities provided by the AddressBook class, based on command line parameters.  It can add new
records, list them, remove one by one, find a particular one based on partial matching for name or lastname.

The AddressBook class is based on vector<> template class from std14+.  At the end is just that and relies heavily on what the vector template
can do or not.  It is quite straightforward.

The idea is to load everything into memory, operate on a standard vector structure, and stores everything back to a file.
This way is not very efficient for a large number of records.  However, as it is like an in-memory database, it is very quick.
For large files, we start to move into the realm of databases so we need to use new approaches to deal with large registers.  We can start
by fixing each record to a fixed-length approach, create an index of the file, and move around based on the index.

# Compiling

```bash
make
```

# Testing

```bash
make testcase TC=[nn]
```
where [nn] is the test case number, available in src/tests/.

# Running

```bash
 ./addressbook
 ./addressbook -add -name NAME -last LASTNAME -phone PHONENUMBER
 ./addressbook -remove ENTRYNUMBER
 ./addressbook -search NAME/LASTNAME/
 ./addressbook -lastsort
 ./addressbook -namesort
```

