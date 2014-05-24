//
//  AudioAnalysis.h
//  testAudio
//
//  Created by Steve Myers on 5/3/14.
//  Copyright (c) 2014 Steve Myers. All rights reserved.
//

#ifndef __testAudio__AudioAnalysis__
#define __testAudio__AudioAnalysis__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "types.h"
#include "tnt2vector.h"
#include <sqlite3.h>
#include "hiberlite.h"


using namespace std;
using namespace essentia;
using namespace hiberlite;

class AudioAnalysis
{
public:
    void analyzeBeats();
    void analyzeFade();
    float beatAfterFadeInIfPresent(float);
    float beatBeforeFadeOutIfPresent(float);
    bool hasBeenAnalyzed();
    bool hasValidData();
    void setFileName(const string&);
    void setFileSize(long long);
    void setBeenAnalyzed(bool);
    void print();
    
private:
    string fileName;
    Real beatConfidence;
    Real bpm;
    long long fileSize;
    int beenAnalyzed;
    
    vector<Real> beatLocations;
    vector<vector<Real>> fadeInLocations;
    vector<vector<Real>> fadeOutLocations;
    
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive& ar);
};

template<class Archive>
void AudioAnalysis::hibernate(Archive& ar)
{
    ar& HIBERLITE_NVP(beatLocations);
    ar& HIBERLITE_NVP(beatConfidence);
    ar& HIBERLITE_NVP(fadeInLocations);
    ar& HIBERLITE_NVP(fadeOutLocations);
    ar& HIBERLITE_NVP(fileName);
    ar& HIBERLITE_NVP(fileSize);
    ar& HIBERLITE_NVP(bpm);
    ar& HIBERLITE_NVP(beenAnalyzed);
}
#endif /* defined(__testAudio__AudioAnalysis__) */
