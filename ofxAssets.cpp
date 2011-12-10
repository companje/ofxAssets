// ofxAssets
// openFrameworks addon for loading and caching image, video and font files
// Created by Rick Companje on 2/25/11.
// Adapted for fonts by Axel Roest, 2011-03-15

// TODO: Use templates instead

#include "ofxAssets.h"

void ofxImageAssets::add(string filename, bool preload) {
    ofImage *asset = new ofImage();	
    ofLog(OF_LOG_VERBOSE, "ofxImageAssets::add(\"" + filename + "\", preload=" + (preload ? "true" : "false") + ")");
    
    //in case of BAD_ACCESS error see http://forum.openframeworks.cc/index.php/topic,7910.0.html
    
    if (!asset->loadImage(filename)) {
        ofLog(OF_LOG_ERROR, "Image not found: " + filename);
        std::exit(1);
    };    	
    assets[filename] = asset;
}

ofImage& ofxImageAssets::operator[](const string& filename) {
    if (!assets[filename]) add(filename);
    return *assets[filename];
}

void ofxVideoAssets::add(string filename, bool preload) {
	ofVideoPlayer *mov = new ofVideoPlayer();
	
	ofLog(OF_LOG_VERBOSE, "ofxAssets::add(\"" + filename + "\", preload=" + (preload ? "true" : "false") + ")");
	
	if (!mov->loadMovie(filename)) {
		ofLog(OF_LOG_ERROR, "Movie not found: " + filename);
		std::exit(1);
	};
	
	assets[filename] = mov;
}

ofVideoPlayer& ofxVideoAssets::operator[](const string& filename) {
	if (!assets[filename]) add(filename);
	return *assets[filename];
}

// fontname and size is combined into one string, because we need both of them as keys in the hash table
void ofxFontAssets::add(string fontnamesize, bool preload) {
	ofTrueTypeFont *fnt = new ofTrueTypeFont();
	
	ofLog(OF_LOG_VERBOSE, "ofxFontAssets::add(\"" + fontnamesize + "\", preload=" + (preload ? "true" : "false") + ")");
	
    istringstream iss(fontnamesize);                    // split up line in words
    string  fontname;
    int    fontsize;
    
    getline(iss, fontname, '_');
    iss >> fontsize;
    
	fnt->loadFont(fontname, fontsize);      // loadFont doesn't return status
	assets[fontnamesize] = fnt;
}

ofTrueTypeFont& ofxFontAssets::operator[](const string& fontnamesize) {
    if (!assets[fontnamesize]) add(fontnamesize);
    return *assets[fontnamesize];
}
