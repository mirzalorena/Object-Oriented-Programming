#include "Undo.h"

UndoAction::~UndoAction()
{
}

void UndoAdd::setAddedEvidence(Evidence newEvidence)
{
	this->addedEvidence.setId(newEvidence.getId());
	this->addedEvidence.setMeasurement(newEvidence.getMeasurement());
	this->addedEvidence.setImageClarityLevel(newEvidence.getimageClarityLevel());
	this->addedEvidence.setQuantity(newEvidence.getQuantity());
	this->addedEvidence.setPhotograph(newEvidence.getPhotograph());
}

void UndoAdd::executeUndo()
{
	repository.deleteEvidence(this->addedEvidence.getId());
}

void UndoAdd::executeRedo()
{
	repository.addEvidence(this->addedEvidence);
}

UndoAdd::UndoAdd(Evidence addedEvidence, Repository & repository):addedEvidence(addedEvidence),repository(repository)
{
	this->addedEvidence = addedEvidence;
}

void UndoRemove::setDeletedEvidence(Evidence newEvidence)
{
	this->deletedEvidence.setId(newEvidence.getId());
	this->deletedEvidence.setMeasurement(newEvidence.getMeasurement());
	this->deletedEvidence.setImageClarityLevel(newEvidence.getimageClarityLevel());
	this->deletedEvidence.setQuantity(newEvidence.getQuantity());
	this->deletedEvidence.setPhotograph(newEvidence.getPhotograph());
}

void UndoRemove::executeUndo()
{
	repository.addEvidence(this->deletedEvidence);
}

void UndoRemove::executeRedo()
{
	repository.deleteEvidence(this->deletedEvidence.getId());
}

UndoRemove::UndoRemove(Evidence deletedEvidence, Repository & repository) : deletedEvidence(deletedEvidence), repository(repository)
{
	this->deletedEvidence = deletedEvidence;
}

void UndoUpdate::setUpdatedEvidence(Evidence newEvidence)
{
	this->newEvidence.setId(newEvidence.getId());
	this->newEvidence.setMeasurement(newEvidence.getMeasurement());
	this->newEvidence.setImageClarityLevel(newEvidence.getimageClarityLevel());
	this->newEvidence.setQuantity(newEvidence.getQuantity());
	this->newEvidence.setPhotograph(newEvidence.getPhotograph());
}

void UndoUpdate::executeUndo()
{
	repository.updateEvidence(this->newEvidence.getId(), this->old);
	//repository.updateEvidence(this->old.getId(), this->newEvidence);
}

void UndoUpdate::executeRedo()
{
	repository.updateEvidence(this->old.getId(), this->newEvidence);
	//repository.updateEvidence(newEvidence.getId(), old);
}

UndoUpdate::UndoUpdate(Evidence old,Evidence newEvidence, Repository & repository):old(old),newEvidence(newEvidence),
repository(repository)
{
	this->old = old;
	this->newEvidence = newEvidence;
}
