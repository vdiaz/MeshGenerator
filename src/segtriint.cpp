#include "segtriint.h"

SegTriInt::SegTriInt(Vect** T,Vect* q,Vect* r){
	segmenttriangleintersection=new SegmentTriangleIntersection();
	segmenttriangleintersection->Vertices[0][0]=T[0]->getPunto().getX();
	segmenttriangleintersection->Vertices[0][1]=T[0]->getPunto().getY();
	segmenttriangleintersection->Vertices[0][2]=T[0]->getPunto().getZ();
	segmenttriangleintersection->Vertices[1][0]=T[1]->getPunto().getX();
	segmenttriangleintersection->Vertices[1][1]=T[1]->getPunto().getY();
	segmenttriangleintersection->Vertices[1][2]=T[1]->getPunto().getZ();
	segmenttriangleintersection->Vertices[2][0]=T[2]->getPunto().getX();
	segmenttriangleintersection->Vertices[2][1]=T[2]->getPunto().getY();
	segmenttriangleintersection->Vertices[2][2]=T[2]->getPunto().getZ();

	this->T[0]=0;
	this->T[1]=1;
	this->T[2]=2;

	this->q[0]=q->getPunto().getX();
	this->q[1]=q->getPunto().getY();
	this->q[2]=q->getPunto().getZ();

	this->r[0]=r->getPunto().getX();
	this->r[1]=r->getPunto().getY();
	this->r[2]=r->getPunto().getZ();
	}

char SegTriInt::aplicar(){
	return segmenttriangleintersection->SegTriInt(T,q,r,p);
	}

SegTriInt::~SegTriInt(){
	delete segmenttriangleintersection;
	}
