import scrapy
class QuotesSpider(scrapy.Spider):
    name = 'quotes'

    def start_requests(self):
        urls = [
            'http://quotes.toscrape.com/page/1/',
            'http://quotes.toscrape.com/page/2/'
        ]
        for url in urls:
            yield scrapy.Request(url=url, callback=self.parse)

    def parse(self, response):
        for quote in response.css('div.quote'):
            yield {
                    'text': quote.css('span.text::text').extract_first(),
                    'author': quote.css('small.quthor::text').extract_first(),
                    'tags': quote.css('div.tags a.tag::text').extract()
            }

        # next page
        next_page = response.css('li.next a::attr(href)').extract_first()
        if next_page is not None:
            url = response.urljoin(next_page)
            yield scrapy.Request(url, callback=self.parse)
