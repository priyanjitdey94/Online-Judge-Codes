

/*
  StringParser Class: Find out ranges from a string separated by ';' or ','.. 
  The range can be of one of the following type:
  1. [ : ]        -> no start and end value. In this case start value is 1 and end value is index of last element
  2. [ x : y ]    -> range given. Start from index x and end at index y.
  3. [ x : p : y] -> stride parameter p. start from x, select channels at intervals p upto y.
*/
class StringParser
{
public:
	StringParser();
	~StringParser();
	std::vector<int> parseString(int rangeValue);
private:
	int convertToInteger(std::string s);        //Changes string to int. Make this public if you want to use it outside this class.
}

/*
	----------------------------------------------------Method definations------------------------------------------------
*/

StringParser::StringParser()
{
	
}

StringParser::~StringParser()
{
	
}

int StringParser::convertToInteger(std::string s)
{
	char ar[20];
    int i, j, k = 0;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            ar[k] = s[i];
            k++;
        }
    }
    if (k>7)
    {
        return 1000000;
    }
    ar[k] = '\0';
    k = atoi(ar);
    return k;
}
/*
	Method parseString returns a vector of integers containing 3a elements(a=0,1,2,3....).
	Consider 3 elements as a group. The first element is the start value, second element is end value, third element is the stride parameter.
*/
std::vector<int> StringParser::parseString(int rangeValue)
{
    std::string s = ",";
    s += getText().toStdString();
    std::vector<int> finalList,separator,rangeseparator;
    int i, j, a, b, k, openb, closeb, otherchar,x,y;
    s += ",";
    for (i = 0; i < s.size(); i++)      //split string by ' , ' or ' ; ' 
    {
        if (s[i] == ';' || s[i] == ',')
        {
            separator.push_back(i);
        }
    }
    for (i = 0; i < separator.size()-1; i++)  // split ranges by ' : ' or ' - '
    {
        j = k = separator[i] + 1;
        openb = closeb = otherchar = 0;
        rangeseparator.clear();
        for (; j < separator[i + 1]; j++)
        {
            if (s[j] == '-' || s[j] == ':')
            {
                rangeseparator.push_back(j);
            }
            else if (((int)s[j] == 32))
            {
                continue;
            }
            else if (s[j] == '[' || s[j] == '{' || s[j] == '(')
            {
                openb++;
            }
            else if (s[j] == ']' || s[j] == '}' || s[j] == ')')
            {
                closeb++;
            }
            else if ( (int)s[j] > 57 || (int)s[j] < 48)
            {
                otherchar++;
            }
        }

        if (openb != closeb || openb > 1 || closeb > 1 || otherchar > 0)  //Invalid input
        {
            continue;
        }
        
        
        for (x = separator[i] + 1; x < separator[i + 1]; x++)       //trim whitespace and brackets from front
        {
            if (((int)s[x] >= 48 && (int)s[x] <= 57) || s[x] == ':' || s[x] == '-')
            {
                break;
            }
        }
        for (y = separator[i + 1] - 1; y > separator[i]; y--)       //trim whitespace and brackets from end
        {
            if (((int)s[y] >= 48 && (int)s[y] <= 57) || s[y] == ':' || s[y] == '-')
            {
                break;
            }
        }
        if (x > y)
        {
            continue;
        }


        if (rangeseparator.size() == 0)   //syntax of form - x or [x]
        {
            a = convertToInteger(s.substr(x, y - x + 1));
            if (a == 0||a>rangeValue)
            {
                continue;
            }
            finalList.push_back(a - 1);
            finalList.push_back(a - 1);
            finalList.push_back(1);
        }
        else if (rangeseparator.size() == 1) // syntax of type - x-y or [x-y]
        {
            a = convertToInteger(s.substr(x, rangeseparator[0] - x + 1));
            b = convertToInteger(s.substr(rangeseparator[0], y - rangeseparator[0] + 1));
            if (a == 0)
            {
                a = 1;
            }
            if (b == 0)
            {
                b = rangeValue;
            }
            if (a > b || a > rangeValue || b > rangeValue)
            {
                continue;
            }
            finalList.push_back(a - 1);
            finalList.push_back(b - 1);
            finalList.push_back(1);
        }
        else if (rangeseparator.size() == 2)   // syntax of type [x:y:z] or x-y-z
        {
            a = convertToInteger(s.substr(x, rangeseparator[0] - x + 1));
            k = convertToInteger(s.substr(rangeseparator[0], rangeseparator[1] - rangeseparator[0] + 1));
            b = convertToInteger(s.substr(rangeseparator[1], y - rangeseparator[1] + 1));
            if (a == 0)
            {
                a = 1;
            }
            if (b == 0)
            {
                b = rangeValue;
            }
            if (k == 0)
            {
                k = 1;
            }
            if (a > b || a > rangeValue || b > rangeValue)
            {
                continue;
            }
            finalList.push_back(a - 1);
            finalList.push_back(b - 1);
            finalList.push_back(k);
        }
    }
    return finalList;
}
