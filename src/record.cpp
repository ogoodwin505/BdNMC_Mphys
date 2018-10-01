#include "record.h"

#include <iomanip>
#include <map>
#include <string>
#include <iterator>
using std::string;
using std::list;        using std::cout;
using std::ostream;     using std::endl;
using std::setw;        using std::map;

const int MAXWIDTH = 15;
double newt;


map<string,int> trans=
  {
    {   "proton",2212 },
    { "pion",111 },
    { "eta",221 },
    { "neutron",2112 },
    { "V",9999 },
    { "DM",18 },
    { "Recoil_DM",18 }, // 18 is 4th gen neutrino close as possible
    { "electron",11} //don't know for dm particles

  };
// need function to convert from beam coordinates to SBND coords to use in larsoft
double * ConvertToSBNDCoords(double *origin_coords,std::shared_ptr<detector> &det) {
  static double SBND_coords[3];
  SBND_coords[0]=(origin_coords[0]-det->GetDetCoordsComponent(0))*100; // may change if detector is not centered on beam. //convert to cm
  SBND_coords[1]=(origin_coords[1]-det->GetDetCoordsComponent(1))*100;
  SBND_coords[2]=(origin_coords[2]-(det->GetDetCoordsComponent(2))+2.5)*100; //2.5 is det length over two will have to change this is decwidth changes
  
  return SBND_coords;
}

ostream& Record_Particles(ostream& outstr, list<Particle> &partlist, std::shared_ptr<detector> &det){
 
  
  std::cout << std::setprecision(5) << std::fixed; 
    for(list<Particle>::iterator it = partlist.begin(); it != partlist.end(); it++){
      newt= (it->origin_coords[3])*1000000000;
      


      if((it->origin_coords[0]==0 && it->origin_coords[1]==0 && it->origin_coords[2]==0 )| trans[it->name]==18){
      outstr << 0;  //check if final state or Dark matter, code to zero so geant doesnt track it
      //not completely happy about this not sure how robust it would be to dark photon case.
      }
      else{
        outstr<<1;

      }
      
      double *SBND_coords;
      SBND_coords = ConvertToSBNDCoords(it->origin_coords, det);
      outstr<< " " << trans[it->name] << " " <<0 << " " <<0 << " "  << 0 <<" " <<  0 << " " <<it->px << " " \
	     << it->py << " "<< it->pz << " " << it->E << " " << it->m;   
      //        outstr << std::setfill(' ') << std::left;
      // outstr << setw(MAXWIDTH) << it->name << setw(MAXWIDTH) << it->px << setw(MAXWIDTH) << it->py << setw(MAXWIDTH) << it->pz << setw(MAXWIDTH) << it->E;
        //if(it->EVENT_SET){
            outstr << " " << SBND_coords[0] << " " << SBND_coords[1] << " " << SBND_coords[2] << " " << newt;
        //}
	    outstr << endl;   
    }
    

    return outstr;
}
