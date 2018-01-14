#pragma once

#include "Chunk.h"
#include "../render/render.h"


// actually renderable filtering is a render thing, should not be done here and will be removed.
// getting relevant chunks though, is the first wave of filtering, determining which chunks will be relevant in the other steps

namespace Actinium::Data
{
	class ChunkExplorer
	{
	public:
		virtual const std::unordered_set<Actinium::Data::Chunk*>		&getRelevantChunks(Actinium::Data::Chunk* that) const = 0;
		virtual const std::unordered_set<Actinium::Render::Renderable*>		&getRenderablesFromChunks(const std::unordered_set<Actinium::Data::Chunk*> &datas) const = 0;
	};

	class DefaultChunkExplorerIp : public ChunkExplorer
	{
	public:
		virtual const std::unordered_set<Actinium::Data::Chunk*>		&getRelevantChunks(Actinium::Data::Chunk* that) const;
		virtual const std::unordered_set<Actinium::Render::Renderable*>		&getRenderablesFromChunks(const std::unordered_set<Actinium::Data::Chunk*> &chunks) const;
	private:
		DefaultChunkExplorerIp();
	};
}

