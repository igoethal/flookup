#include "pch.h"
#include "levenshtein.h"

INT16 levenshtein_distance_fixed(LPCSTR s1, INT16 l1, LPCSTR s2, INT16 l2)
{
    //Matrix of characters were the calculation will be done
    INT16 track;
    INT16 dist[MAXSIZE+1][MAXSIZE+1];

    //We will only compare the first MAXSIZE characters
    if (l1 > MAXSIZE) l1 = MAXSIZE;
    if (l2 > MAXSIZE) l2 = MAXSIZE;

    for (INT16 i = 0; i <= l1; i++) {
        dist[0][i] = i;
    }

    for (INT16 j = 0; j <= l2; j++) {
        dist[j][0] = j;
    }

    for (INT16 j = 1; j <= l1; j++) {
        for (INT16 i = 1; i <= l2; i++) {
            if (s1[j - 1] == s2[i - 1]) {
                track = 0;
            }
            else {
                track = 1;
            }
            INT16 t = MIN((dist[i - 1][j] + 1), (dist[i][j - 1] + 1));
            dist[i][j] = MIN(t, (dist[i - 1][j - 1] + track));
        }
    }

    INT16 r = dist[l2][l1];

    return r;
}