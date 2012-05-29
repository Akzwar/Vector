#include <vector>
#include <stdio.h>
using namespace std;

class Vect
{
    private:
	
	vector< long double > data;	

    public:

        Vect(){}
	
	int size() const
	{
		return data.size();
	}	
	Vect( int length )
	{
		for( int i = 0; i < length; i++ )
			this->data.push_back(0);
	
	}
        Vect(const Vect &V)
        {
		this->data.clear();
		for( int i = 0; i<V.size(); i++)
			this->data.push_back(V.data[i]);
        }
        Vect(long double *n, int length)
        {
		this->data.clear();
		for( int i = 0; i < length; i++ )
			data.push_back(n[i]);
        }

        Vect operator + (const Vect& V) const
        {
            	Vect retVect;
		for( int i = 0; i < this->size(); i++)
                	retVect.data.push_back(V.data[i]+this->data[i]);
		return retVect;
        }

        void operator += (const Vect& V)
        {	    
		for( int i = 0; i < this->size(); i++ )
			this->data[i]+=V.data[i];
        }

        Vect operator * (const long double Cross) const
        {
            	Vect retVect;
	    	for( int i = 0; i < this->size(); i++)
			retVect.data.push_back( this->data[i] * Cross );
            	return retVect;
        }

        bool operator == (const Vect& V) const
        {
		if( V.size() != this->size())
			return false;
		for( int i = 0; i < this->size(); i++ )
			if( this->data[i] != V.data[i])
				return false;
		return true;
        }

        bool operator != (const Vect& V) const
        {
            return !((*this)==V);
        }

        void operator = (const Vect& V)
        {
		this->data.clear();
		for( int i = 0; i < V.size(); i++ )
			this->data.push_back( V.data[i] );
        }
	
	long double operator [] ( int index )
	{
		return data[index];
	}
	
	void SetElement( int index, long double value)
	{
		data[index] = value;
	}
        //double Angle()const {return atan2(Y2, long double Y1);}
};

