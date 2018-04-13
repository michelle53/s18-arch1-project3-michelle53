#ifndef abPacman_included
#define abPacman_included

#include "shape.h"

/** AbShape circle
 *  
 *  chords should be a vector of length radius + 1.  
 *  Entry at index i is 1/2 chord length at distance i from the circle's center.  
 *  This vector can be generated using lcdLib's computeChordVec() (lcddraw.h).
 */ 
typedef struct AbPacman_s {
  void (*getBounds)(const struct AbPacman_s *pacman, const Vec2 *centerPos, Region *bounds);
  int (*check)(const struct AbPacman_s *pacman, const Vec2 *centerPos, const Vec2 *pixel);
  const u_char *chords;
  const u_char radius;
} AbPacman;

/** Required by AbShape
 */
void abPacmanGetBounds(const AbPacman *pacman, const Vec2 *circlePos, Region *bounds);

/** Required by AbShape
 */
int abPacmanCheck(const AbPacman *pacman, const Vec2 *circlePos, const Vec2 *pixel);

int abSlicedPacmanCheck(const AbPacman *pacman, const Vec2 *circlePos, const Vec2 *pixel);

#endif



