const Observer = require('./lib/observer')
const Channel = require('./lib/chanel')

class Reporter extends Observer {
    update(info) {
        console.log(`
    ===========================
    News from the world: ${info}!
    
    `)
    }
}
const CNN = new Channel()

const Tony = new Reporter()
const Rick = new Reporter()
const Tori = new Reporter()

CNN.addObserver(Tony)
CNN.addObserver(Rick)
CNN.addObserver(Tori)

CNN.addNews('Lakers go to the finals')



