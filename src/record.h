#ifndef GUARD_record_h
#define GUARD_record_h

#include <iostream>
#include <list>

#include "Particle.h"
#include "detector.h"

std::ostream& Record_Particles(std::ostream &, std::list<Particle> &,std::shared_ptr<detector> &);

#endif
