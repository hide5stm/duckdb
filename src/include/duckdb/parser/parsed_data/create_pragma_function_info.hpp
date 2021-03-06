//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/parser/parsed_data/create_pragma_function_info.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/parser/parsed_data/create_function_info.hpp"
#include "duckdb/function/pragma_function.hpp"

namespace duckdb {

struct CreatePragmaFunctionInfo : public CreateFunctionInfo {
	CreatePragmaFunctionInfo(PragmaFunction function) : CreateFunctionInfo(CatalogType::PRAGMA_FUNCTION_ENTRY) {
		functions.push_back(move(function));
		this->name = function.name;
	}
	CreatePragmaFunctionInfo(string name, vector<PragmaFunction> functions_)
	    : CreateFunctionInfo(CatalogType::PRAGMA_FUNCTION_ENTRY), functions(move(functions_)) {
		this->name = name;
		for (auto &function : functions) {
			function.name = name;
		}
	}

	vector<PragmaFunction> functions;
};

} // namespace duckdb
