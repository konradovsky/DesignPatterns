const Observable = require('./observable')

class Channel extends Observable {
    constructor() {
        super()
    }
    addNews(news) {
        this.notify(news)
    }
}
module.exports = Channel