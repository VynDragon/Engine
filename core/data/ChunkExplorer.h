#pragma once

#include "Chunk.h"

// mostly useless class

namespace Actinium::Data
{
	class ChunkExplorer
	{
	public:
		virtual const std::unordered_set<Actinium::Data::Chunk*>		&getRelevantChunks(Actinium::Data::Data* that) = 0;
		virtual const std::unordered_set<Actinium::Data::Chunk*>		&getRenderables(const std::unordered_set<Actinium::Data::Data*> &datas, const std::type_index &that) = 0;
	};

	class DefaultChunkExplorerIp : public ChunkExplorer
	{
	public:
		virtual const std::unordered_set<Actinium::Data::Chunk*>		&getRelevantChunks(Actinium::Data::Data* that);
		virtual const std::unordered_set<Actinium::Data::Chunk*>		&getRenderables(const std::unordered_set<Actinium::Data::Data*> &datas, const std::type_index &that);
	private:
		DefaultChunkExplorerIp();
	};
}

