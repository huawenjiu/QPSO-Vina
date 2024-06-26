/*
        PSOVina version 2.0  

        Authors: Giotto H. K. TAI  <giottotai@yahoo.com.hk>

                 Shirley W. I. Siu <shirleysiu@umac.mo>


        Computational Biology and Bioinformatics Lab

        University of Macau

        http://cbbio.cis.umac.mo

*/
#ifndef PSO_H_
#define PSO_H_

#include "common.h"
#include "conf.h"
#include <vector>

class pso
{	
public:
	struct bird{
		     vec velocity,vO;  //velocity of position, velocity of orientation
		     
		     vec pbest_pos;
		     vec current_position;
 
		     qt pbest_orientation; 
		     qt current_orientation;
		     
		     fl* pbest_torsion;
		     fl* current_torsion;
		     fl* vT;    //velocity of torsion
		     
		     double pbest_fit,tmp_fit;  

	};
	
	int torsionSize;
	double w,c1,c2;						// weight, learning coefficient(1&2)
	rng g;

	int number;							//number of birds
	vec corner1,corner2;				//corners of search box
	
	static vec gbest_position;			//global best of degree of freedom vector
	static qt gbest_orientation;		//global best of degree of freedom vector
	static fl* gbest_torsion;			//global best of degree of freedom vector
	
	static double gbest_fit;			//global best value
	
	std::vector<bird> particle;
	
	
	  double R1Max_;
	  double R1Min_;
	  double R2Max_;
	  double R2Min_;
	
	
	pso(int,double,double,double,const vec,const vec,rng&,conf&);
	void init(rng&,conf&);
    
    /*Update Velocity for vector*/
    void updateVelocity(rng&,int,double,double);
    void updateVelocityO(rng&,int,double,double);
    void updateVelocityT(rng&,int,sz,double,double);
    
    
    /*Compute the new pose*/
    void computeNewPositions(int, int, int, rng&);
	void computeNewOrientation(int, int, int, rng&);
	void computeNewTorsion(int,rng&,sz, int, int);
    
    
    /*Update personal best value*/
	void updatePersonalBest(int,double);
    
    /*Update global best value*/
	void updateGlobalBest(int);
	void updateGlobalBest_1(fl);
    
    /*Get personal best value*/
	double getPersonalBest(int);	//return the personal best value
    
    /*Set personal best vector*/
    void updateBestPosition(int,vec);
    void updateBestOrientation(int,qt);
    void updateBestTorsion(int,fl,sz);


    /*Get current vector*/
	vec getCurrentPosition(int);
    qt getCurrentOrientation(int);
    fl getCurrentTorsion(int,sz);
    
};


#endif /*PSO_H_*/
