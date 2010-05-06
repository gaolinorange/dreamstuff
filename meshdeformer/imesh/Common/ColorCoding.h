/**ColorCoding

   (0,0,255)     Blue
   (0,255,255)   Cambridge blue
   (0,255,0)     Green
   (255,255,0)   Yellow
   (255,0,0)     Red
*/

#ifndef COLORCODING_H
#define COLORCODING_H

#include "glheaders.hpp"

/**
   ColorCoding:
   @brief:
   colorcoding the datas
*/

class Color {
public:
  Color(  ) {
    
  }
  Color( int _r, int _g, int _b ) {
    r = _r, g = _g, b = _b;
  }
  ~Color(  ) {
    
  }
  Color( const Color& _color ) {
    r = _color.r;
    g = _color.g;
    b = _color.b;
  }

  bool operator==( const Color& _color ) {
    return ( (r-_color.r) == 0 &&
             ( g-_color.g )==0 &&
             ( b-_color.b )==0 );
  }
  
  int r,g,b;  
};

const Color BLUE  = Color( 0,0,255 );
const Color RED   = Color( 255,0,0 );
const Color GREEN = Color( 0,255,0 );


template<typename DataType>
class ColorCoding
{
public:
	ColorCoding(DataType minValue,DataType maxValue)
	{
		m_MinValue = minValue; m_MaxValue = maxValue;
		m_NumRange = 4; //
		
		setMinMax(minValue,maxValue);
	}
	~ColorCoding(){}
protected:
	DataType m_MinValue;
	DataType m_MaxValue;

	DataType m_Median[5];//
	int m_NumRange;
	DataType m_Range;
public:
	void setMinMax(DataType minValue,DataType maxValue)
	{
		m_MinValue = minValue;
		m_MaxValue = maxValue;

		m_Median[0] = (DataType)((m_MaxValue-m_MinValue) * 0.1) + m_MinValue;
		m_Median[4] = (DataType)((m_MaxValue-m_MinValue) * 0.9) + m_MinValue;

		//setup the ranges

		m_Range = (DataType)((m_Median[4]-m_Median[0])*1.0/m_NumRange);

		for(int i = 1; i < 4; i++)
		{
			m_Median[i] = m_Median[0] + m_Range * i;
		}
	}

public:
	/** colorCoding:
      @param: data value
      @return: the Color related with the input data
	*/
	Color colorCoding(DataType data)
	{
		int u; //for interpolation
		//begin color coding
		Color color;
		if(data <= m_Median[2]) //Green
		{
			if(data <= m_Median[0]) //BLUE
			{
				color = BLUE;
			}
			else if(data <= m_Median[1]) //BLUE->Cambridge BLUE,  
			{
				u = int((float)(data-m_Median[0])/m_Range * 255);
				color = Color(0,u,255);
			}
			else  //Cambridge BLUE to Green,
			{
				u = int((float)(data-m_Median[1])/m_Range * 255);
				color = Color(0,255,255-u);
			}
		}
		else  //data > median[2]
		{
			if(data >= m_Median[4]) //Red
			{
				color = RED;
			}
			else if(data >= m_Median[3]) //YELLOW->Red,
			{
				u = int( (float)(data-m_Median[3])/m_Range * 255);
				color =  Color(255,255-u,0);
			}
			else  //Green->Yellow,
			{
				u = int( (float)(data-m_Median[2])/m_Range * 255);
				color = Color(u,255,0);
			}
		}

		return color;
	}

	DataType getMaxValue()
	{
		return m_MaxValue;
	}
	DataType getMinValue()
	{
		return m_MinValue;
	}
	//for debugging
	void printMedians()
	{
		for(int i = 0; i < 5; i++)
		{
			std::cout<<"Median "<<i<<" : "<<m_Median[i]<<std::endl;
		}
	}
};

#endif
