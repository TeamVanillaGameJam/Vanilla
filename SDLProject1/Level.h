#pragma once
#include <string>
#include <vector>
#include "Vector2D.h"
struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};

class Layer
{
public:
	virtual void render() = 0;
	virtual void update() = 0;
protected:
	virtual ~Layer() {}
};

class Level
{
public:
	~Level() {}
	void update();
	void render();

	std::vector<Tileset>* getTilesets()
	{
		return &m_tilesets;
	}

private:
	Level() = default;
	std::vector<Tileset> m_tilesets; // the rows of the map
	std::vector<Layer*> m_layers;
};


/*
for(int cols = 0; cols < m_width; cols++)
 {
 data[rows][cols] = gids[rows * m_width + cols];
 }
 *///I gues that will be in use when loading the tile map