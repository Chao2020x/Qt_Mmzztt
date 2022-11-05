package biquge

import (
	"ants/extractors"
)

func init() {
	extractors.Register("youku", New())
}

type extractor struct{}

// New returns a youku extractor.
func New() extractors.Extractor {
	return &extractor{}
}

// Extract is the main function to extract the data.
func (e *extractor) Extract(url string, option extractors.Options) ([]*extractors.Data, error) {
	return nil, nil
}
