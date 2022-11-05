package extractors

import "sync"

var lock sync.RWMutex
var extractorMap = make(map[string]Extractor)

// Register registers an Extractor.
func Register(domain string, e Extractor) {
	lock.Lock()
	extractorMap[domain] = e
	lock.Unlock()
}
