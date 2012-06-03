#include <vector>
#include <stdio.h>

#define V_X 0
#define V_Y 1
#define V_Z 2

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
	Vect( long double X, long double Y, long double Z )
	{
		this->data.push_back(X);
		this->data.push_back(Y);
		this->data.push_back(Z);
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

	const Vect operator * ( long double Cross)
        {
            	Vect retVect;
	    	for( int i = 0; i < this->size(); i++)
			retVect.data.push_back( this->data[i] * Cross );
            	return retVect;
        }

	long double operator * ( const Vect& V )
	{
		long double ret = 0;
		for( int i = 0; i < this->size(); i++ )
			ret += this->data[i] * V.data[i] ;
		return ret;
	}

	Vect operator % ( const Vect& V )
	{
		Vect retVect(3);
		retVect[V_X] = this->data[V_Y] * V.data[V_Z] - this->data[V_Z] * V.data[V_Y];
		retVect[V_Y] = this->data[V_Z] * V.data[V_X] - this->data[V_X] * V.data[V_Z];
		retVect[V_Z] = this->data[V_X] * V.data[V_Y] - this->data[V_Y] * V.data[V_X];
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
	
 	long double& operator [] ( int index )
	{
		return data[index];
	}
	
	void SetElement( int index, long double value)
	{
		data[index] = value;
	}
	
	void print()
	{
		for(int i = 0; i < this->size(); i++)
			if( i != this->size() - 1 )
				printf("[%f],", this->data[i]);
			else 
				printf("[%f]\n", this->data[i]);
	}
        //double Angle()const {return atan2(Y2, long double Y1);}
};

