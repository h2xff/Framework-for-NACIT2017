#include "sys_fun.h"

/*================================================================
 * 函数：CreateFolder(string name, bool output)
 *
 * 参数：
 *      string name:  需要创建的文件夹名称
 *      bool output:  是否在控制台输出相关信息
 *
 * 例程：
 *      1. 若在当前工程生成路径，生成一个NCServer文件夹，则调用：
 *          CreateFolder("NCServer", true);
 *      2. 若在当前工程生成路径下的NCRecord文件夹下创建新文件夹NCServer，且NCRecord文件夹已经存在，则调用：
 *          CreateFolder("NCRecord/NCServer", true);
 =================================================================
 */
bool CreateFolder(string name, bool output)
{
    string path = "./";
    path += name;
    if(path[path.length() - 1] != '/')
        path += '/';
//        cout<<"hahaha"<<endl;

    int state = mkdir(string2char(path), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    const char* filename = path.c_str();
    fstream strm(filename, ios::out | ios::app);
    if(state == 0)
    {
        if(!strm.is_open())
        {
            if(output)
                cout<<"Creating the Folder \""<<path<<"\"Done."<<endl;
        }
        return true;
    }
    else
    {
        if(!strm.is_open())
        {
            if(output)
            {
                cout<<"The Folder \""<<name<<"\" Has Created."<<endl;
                return false;
            }
        }

        cout<<"Create Folder UNKNOWN Return Value."<<endl;
        return false;
    }
}
