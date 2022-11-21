# prorgram for addressbook


# function to create addressbook
function createBook()
{
    echo "Enter the name of the addressbook"
    read bookName
    if [ -f $bookName ]
    then
        echo "Addressbook already exists"
    else
        touch $bookName
        echo "Addressbook created successfully"
    fi
}

# function to insert student records(name roll)
function insertRecord()
{
    echo "Enter the name of the addressbook"
    read bookName
    if [ -f $bookName ]
    then
        echo "Enter the name of the student"
        read name
        echo "Enter the roll number of the student"
        read roll
        echo "$name $roll" >> $bookName
        echo "Record inserted successfully"
    else
        echo "Addressbook does not exist"
    fi
}

# function to display student records
function displayRecord()
{
    echo "Enter the name of the addressbook"
    read bookName
    if [ -f $bookName ]
    then
        echo "Name Roll"
        cat $bookName
    else
        echo "Addressbook does not exist"
    fi
}

# function to search student records
function searchRecord()
{
    echo "Enter the name of the addressbook"
    read bookName
    if [ -f $bookName ]
    then
        echo "Enter the name of the student"
        read name
        echo "Name Roll"
        p = grep -i $name $bookName
        if [ -z $p ]
        then
            echo "Record not found"
        else
            echo $p
        fi
    else
        echo "Addressbook does not exist"
    fi
}

# function to delete student records
function deleteRecord()
{
    echo "Enter the name of the addressbook"
    read bookName
    if [ -f $bookName ]
    then
        echo "Enter the name of the student"
        read name
        sed -i "/$name/d" $bookName
        echo "Record deleted successfully"
    else
        echo "Addressbook does not exist"
    fi
}

# function to update student records
function updateRecord()
{
    echo "Enter the name of the addressbook"
    read bookName
    if [ -f $bookName ]
    then
        echo "Enter the name of the student"
        read name
        echo "Enter the new roll number of the student"
        read roll
        sed -i "/$name/c $name $roll" $bookName
        echo "Record updated successfully"
    else
        echo "Addressbook does not exist"
    fi
}
+P

