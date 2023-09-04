#include <iostream>

using namespace std;

// 这个不推荐大家使用命名空间，建议大家使用：：域作用符

struct Point2D
{
    double X,Y;

};
/*
* 定义墙底部开始到结束的坐标点
  墙的海拔，
  墙的高度
*/


class Wall
{
   Point2D m_start, m_End ;

   int m_elevation, m_height;

public:
    Wall(Point2D start, Point2D end, int elevation, int height)
    :m_start(start), m_End(end), m_elevation(elevation), m_height(height)
    {
    }
    const Point2D& GetStartPoint()const
    {
        return m_start;
    }
    
};

enum class EMaterial
{
    brick,
    aerated_concrete,
    drywall
};

class SolidWall : public Wall
{
    int m_Width;
    EMaterial m_Material;
public:
    // SolidWall(Point2D start, Point2D end, int elevation, int height, int width, EMaterial material)
    // :Wall(start, end, elevation,height),m_Width(width),m_Material(material)
    // {

    // }

    SolidWall(Point2D start, Point2D end, int elevation, int height, int width, EMaterial material)
    :Wall(start, end, elevation,height),m_Width(width),m_Material(material)
    {
        if(elevation<0 && material ==EMaterial::aerated_concrete)
        {
            throw invalid_argument("elevation!");
        }
        if(width<120 && material == EMaterial::brick)
        {
            throw invalid_argument("width!");
        }
    }

    void ShowInfo() const
    {
        // 这里不推荐使用此方法，个人觉得重载 << 流操作符比较好，不依赖与std
        cout << "start : (" << GetStartPoint().X << "," << GetStartPoint().Y  <<")......"<<endl;
    }

};





int main()
{

    {
        SolidWall solidWall {{0.0,2.0},{0.0,2.0},100,100,150,EMaterial::brick};
        solidWall.ShowInfo();
    }

    cout << "hello World!" << endl;

    return 0;
}