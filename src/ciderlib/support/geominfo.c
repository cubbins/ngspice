/**********
Copyright 1991 Regents of the University of California.  All rights reserved.
Author:	1987 Kartikeya Mayaram, U. C. Berkeley CAD Group
Author:	1991 David A. Gates, U. C. Berkeley CAD Group
**********/

#include "ngspice.h"
#include "gendev.h"
#include "macros.h"
#include "memory.h"

void printCoordInfo(CoordInfo *pFirstCoord)
{
  CoordInfo *pCoord;
  
  for ( pCoord = pFirstCoord; pCoord != NIL(CoordInfo);
      pCoord = pCoord->next ) {
    fprintf(stderr, "mesh number=%4d  location=%11.4e\n",
	    pCoord->number, pCoord->location );
  }
}

void killCoordInfo(CoordInfo *pFirstCoord)
{
  CoordInfo *pCoord, *pKill;
  
  for ( pCoord = pFirstCoord; pCoord != NIL(CoordInfo); ) {
    pKill = pCoord;
    pCoord = pCoord->next;
    FREE( pKill );
  }
}

void ONEprintDomainInfo(DomainInfo *pFirstDomain)
{
  DomainInfo *pDomain;
  
  for ( pDomain = pFirstDomain; pDomain != NIL(DomainInfo);
       pDomain = pDomain->next ) {
    fprintf( stderr, "domain id=%4d  mat=%4d  ixLo=%4d  ixHi=%4d\n",
	    pDomain->id, pDomain->material, pDomain->ixLo, pDomain->ixHi );
  }
}

void TWOprintDomainInfo(DomainInfo *pFirstDomain)
{
  DomainInfo *pDomain;
  
  for ( pDomain = pFirstDomain; pDomain != NIL(DomainInfo);
       pDomain = pDomain->next ) {
    fprintf( stderr,
	    "domain id=%4d  mat=%4d  ixLo=%4d  ixHi=%4d  iyLo=%4d  iyHi=%4d\n",
	    pDomain->id, pDomain->material,
	    pDomain->ixLo, pDomain->ixHi,
	    pDomain->iyLo, pDomain->iyHi);
  }
}

void killDomainInfo(DomainInfo *pFirstDomain)
{
  DomainInfo *pDomain, *pKill;
  
  for ( pDomain = pFirstDomain; pDomain != NIL(DomainInfo); ) {
    pKill = pDomain;
    pDomain = pDomain->next;
    FREE( pKill );
  }
}

void ONEprintBoundaryInfo(BoundaryInfo *pFirstBoundary)
{
  BoundaryInfo *pBoundary;
  
  for ( pBoundary = pFirstBoundary; pBoundary != NIL(BoundaryInfo);
       pBoundary = pBoundary->next ) {
    fprintf( stderr,
	    "boundary dom=%4d  nbr=%4d  ixLo=%4d  ixHi=%4d\n",
	    pBoundary->domain, pBoundary->neighbor,
	    pBoundary->ixLo, pBoundary->ixHi );
  }
}

void TWOprintBoundaryInfo(BoundaryInfo *pFirstBoundary)
{
  BoundaryInfo *pBoundary;
  
  for ( pBoundary = pFirstBoundary; pBoundary != NIL(BoundaryInfo);
       pBoundary = pBoundary->next ) {
    fprintf( stderr,
	    "boundary dom=%4d  nbr=%4d  ixLo=%4d  ixHi=%4d  iyLo=%4d  iyHi=%4d\n",
	    pBoundary->domain, pBoundary->neighbor,
	    pBoundary->ixLo, pBoundary->ixHi,
	    pBoundary->iyLo, pBoundary->iyHi);
  }
}

void killBoundaryInfo(BoundaryInfo *pFirstBoundary)
{
  BoundaryInfo *pBoundary, *pKill;
  
  for ( pBoundary = pFirstBoundary; pBoundary != NIL(BoundaryInfo); ) {
    pKill = pBoundary;
    pBoundary = pBoundary->next;
    FREE( pKill );
  }
}

void TWOprintElectrodeInfo(ElectrodeInfo *pFirstElectrode)
{
  ElectrodeInfo *pElectrode;
  
  for ( pElectrode = pFirstElectrode; pElectrode != NIL(ElectrodeInfo);
       pElectrode = pElectrode->next ) {
    fprintf( stderr,
	"electrode id=%4d  ixLo=%4d  ixHi=%4d  iyLo=%4d  iyHi=%4d\n",
	pElectrode->id, pElectrode->ixLo, pElectrode->ixHi,
	pElectrode->iyLo, pElectrode->iyHi );
  }
}

void killElectrodeInfo(ElectrodeInfo *pFirstElectrode)
{
  ElectrodeInfo *pElectrode, *pKill;
  
  for ( pElectrode = pFirstElectrode; pElectrode != NIL(ElectrodeInfo); ) {
    pKill = pElectrode;
    pElectrode = pElectrode->next;
    FREE( pKill );
  }
}
