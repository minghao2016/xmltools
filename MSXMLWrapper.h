#pragma once

#include "XmlWrapperInterface.h"
#include "MSXMLHelper.h"

class MSXMLWrapper : public XmlWrapperInterface {
	void addErrorToVector(IXMLDOMParseError* pXMLErr, const wchar_t* szDesc = L"An unexpected error occurred");
	void buildErrorsVector(IXMLDOMParseError* pXMLErr, const wchar_t* szDesc = L"An unexpected error occurred");

public:
	MSXMLWrapper();
	~MSXMLWrapper();

	int getCapabilities();
	bool checkSyntax(const char* xml, size_t size);
	bool checkValidity(const char* xml, size_t size, std::wstring schemaFilename = L"", std::wstring validationNamespace = L"");
	std::vector<XPathResultEntryType> xpathEvaluate(const char* xml, size_t size, std::wstring xpath, std::wstring ns = L"");
	bool xslTransform(const char* xml, size_t xmllen, std::wstring xslfile, XSLTransformResultType* out, std::wstring options = L"", UniMode srcEncoding = UniMode::uniEnd);
};

