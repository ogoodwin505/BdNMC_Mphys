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
    { "DM",1000022 },
    { "Recoil_DM",1000022 } //don't know for dm particles

  };






















ostream& Record_Particles(ostream& outstr, list<Particle> &partlist){
  std::cout << std::setprecision(5) << std::fixed; 
    for(list<Particle>::iterator it = partlist.begin(); it != partlist.end(); it++){
      newt= (it->origin_coords[3])*1000000000;
                                          
      outstr << 1 << " " << trans[it->name] << " " <<0 << " " <<0 << " "  << 0 <<" " <<  0 << " " <<it->px << " " \
	     << it->py << " "<< it->pz << " " << it->E << " " << it->m;   
      //        outstr << std::setfill(' ') << std::left;
      // outstr << setw(MAXWIDTH) << it->name << setw(MAXWIDTH) << it->px << setw(MAXWIDTH) << it->py << setw(MAXWIDTH) << it->pz << setw(MAXWIDTH) << it->E;
        //if(it->EVENT_SET){
            outstr << " " << it->origin_coords[0] << " " << it->origin_coords[1] << " " << it->origin_coords[2] << " " << newt;
        //}
	    outstr << endl;   
    }
    

    return outstr;
}
